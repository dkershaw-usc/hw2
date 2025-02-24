#include "my_ds.h"
#include "datastore.h"
#include <set>

MyDataStore::~MyDataStore()
{
    // Delete Product objects
    for(std::map<std::string,std::set<Product*>>::iterator it  = keywordProductMap.begin(); 
                                                           it != keywordProductMap.end(); 
                                                           ++it)
    {
        if(!it->second.empty()) it->second.clear();
    }
    keywordProductMap.clear();
    for(std::set<Product*>::iterator it = products.begin();
                                     it != products.end();
                                    ++it)
    {
        delete *it;
    }
    // Delete User objects
    for(std::map<User*,std::vector<Product*>>::iterator it  = userCartMap.begin(); 
                                                     it != userCartMap.end(); 
                                                     ++it)
    {
        it->second.clear();
        delete (it)->first;
    }
    userCartMap.clear();
    users.clear();
}

void MyDataStore::addProduct(Product* p)
{
    if(p == nullptr) return;

    std::set<std::string> ingestedKeywords = p->keywords();

    for(std::set<std::string>::iterator it = ingestedKeywords.begin(); 
                                        it != ingestedKeywords.end(); 
                                        ++it)
    {
        if(keywordProductMap.find(*it) != keywordProductMap.end())
        {
            keywordProductMap[(*it)].insert(p);
        }
        else
        {
            std::set<Product*> s;
            s.insert(p);
            keywordProductMap.insert(std::pair<std::string,std::set<Product*>>((*it),s));
        }
    }

    products.insert(p);
}

void MyDataStore::addUser(User* u)
{
    std::vector<Product*> cart;
    userCartMap.insert(std::pair<User*,std::vector<Product*>>(u,cart));
    users.insert(u);
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
    std::vector<Product*> out;
    std::set<Product*> gather = {};

    if(type == 1) 
    {// OR search
        for(std::vector<std::string>::iterator it = terms.begin(); 
                                               it != terms.end(); 
                                               ++it)
        {
            if(this->keywordProductMap.find(*it) != this->keywordProductMap.end())
            {
                gather = setUnion(gather,(this->keywordProductMap[(*it)]));
            }
        }
    }
    else if(type == 0)
    { // AND search
        // TODO: investgate recursive sol'n
        // Iteratively, for now:
        // - Gather first set of products
        // - Find intersection between this and all subsequent sets
        gather = getProductsForKeyword(terms[0]);
        for(std::vector<std::string>::iterator it = terms.begin(); it != terms.end(); ++it)
        {
            gather = setIntersection(gather, getProductsForKeyword(*it));
        }
    }
    else
    {
        std::cerr << "Unsupported search type. \n 0 - AND \n 1 - OR" << std::endl;
    }

    for(std::set<Product*>::iterator it = gather.begin(); it != gather.end(); ++it)
    {
        out.push_back(*it);
    }
    return out;
}

void MyDataStore::dump(std::ostream& ofile)
{
    ofile << "<products>\n";
    std::set<Product*> out;
    for(std::map<std::string,std::set<Product*>>::iterator it  = keywordProductMap.begin(); 
                                                           it != keywordProductMap.end(); 
                                                           ++it)
    {
        for(std::set<Product*>::iterator jit = keywordProductMap[it->first].begin(); 
                                         jit != keywordProductMap[it->first].end(); 
                                         ++jit)
        {
            out.insert(*jit);
        }
    }
    for(std::set<Product*>::iterator it = out.begin(); 
                                     it != out.end(); 
                                     ++it)
    {
        (**it).dump(ofile);
    }
    ofile << "</products>\n";
    ofile << "<users>\n";
    for(std::map<User*,std::vector<Product*>>::iterator it = userCartMap.begin();
                                  it != userCartMap.end();
                                  ++it)
    {
        (*it->first).dump(ofile);
    }
    ofile << "</users>\n";
}

std::set<Product*>& MyDataStore::getProductsForKeyword(std::string term)
{
    return keywordProductMap[term];
}

void MyDataStore::addToCart(std::string u, Product* p)
{
    User* user = findUserByName(u);
    if(user == nullptr)
    {
        std::cout << "Invalid username" << std::endl;
        return;
    }

    userCartMap[user].push_back(p);
}

void MyDataStore::viewCart(std::string u)
{
    User* user = findUserByName(u);
    if(user == nullptr)
    {
        std::cout << "Invalid username" << std::endl;
        return;
    }

    int idx = 1;
    // std::vector<Product*> prods = userCartMap[user];
    for(std::vector<Product*>::iterator it = userCartMap[user].begin(); 
                                        it != userCartMap[user].end(); 
                                        ++it)
    {
        std::cout << "Item " << idx << std::endl;
        idx++;
        std::cout << (**it).displayString() << "\n\n";
    }
}

void MyDataStore::buyCart(std::string u)
{
    User* user = findUserByName(u);
    if(user == nullptr)
    {
        std::cout << "Invalid username" << std::endl;
        return;
    }
    
    std::vector<Product*> prods = userCartMap[user];
    for(std::vector<Product*>::iterator it = prods.begin(); 
                                        it != prods.end(); 
                                        ++it)
    {
        tryBuy(user,(*it));
    }
}

void MyDataStore::tryBuy(User* u, Product* p)
{
    // If the user has enough money:
    if(u->getBalance() >= p->getPrice())
    {
        // If the product is in stock:
        if(p->getQty() > 0)
        {
            // Buy it.
            p->subtractQty(1);
            u->deductAmount(p->getPrice());
        }
    }
    else
    {
        // Don't buy it. Move on.
    }
}

User* MyDataStore::findUserByName(std::string u)
{
    for(std::map<User*,std::vector<Product*>>::iterator it = userCartMap.begin();
                                                        it != userCartMap.end();
                                                        ++it)
    {
        if(it->first->getName() == u)
        {
            return (*it).first;
        }
    }
    return nullptr;
}