#include "my_ds.h"

void MyDataStore::addProduct(Product* p)
{
    std::set<std::string> ingestedKeywords = p->keywords();

    for(std::set<std::string>::iterator it = ingestedKeywords.begin(); it != ingestedKeywords.end(); ++it)
    {
        if(keywordProductMap.find(*it) != keywordProductMap.end())
        {
            keywordProductMap[*it].insert(p);
        }
        else
        {
            std::set<Product*> s;
            s.insert(p);
            keywordProductMap.insert(std::pair<std::string,std::set<Product*>>(*it,s));
        }
    }
}

void MyDataStore::addUser(User* u)
{
    std::queue<Product*> cart;
    userCartMap.insert(std::pair<User*,std::queue<Product*>>(u,cart));
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
    std::vector<Product*> out;
    std::set<Product*> gather;
    std::set<Product*> andGather;

    switch (type)
    {
    case 1: // OR search
        for(std::vector<std::string>::iterator it = terms.begin(); it != terms.end(); ++it)
        {
            gather.insert(keywordProductMap[*it].begin(), keywordProductMap[*it].end());
        }
        break;
    case 0: // AND search
        // TODO: investgate recursive sol'n
        // Iteratively, for now:
        // - Gather first set of products
        // - Find intersection between this and all subsequent sets
        gather = keywordProductMap[terms.front()];
        for(std::vector<std::string>::iterator it = terms.begin(); it != terms.end(); ++it)
        {
            gather = setIntersection(gather, keywordProductMap[*(it)]);
        }
        break;
    default:
        std::cerr << "Unsupported search type. \n 0 - AND \n 1 - OR" << std::endl;
        break;
    }

    for(std::set<Product*>::iterator it = gather.begin(); it != gather.end(); ++it)
    {
        out.push_back(*it);
    }
    return out;
}

void MyDataStore::dump(std::ostream& ofile)
{
    for(std::map<std::string,std::set<Product*>>::iterator it = keywordProductMap.begin(); it != keywordProductMap.end(); ++it)
    {
        for(std::set<Product*>::iterator jit = keywordProductMap[it->first].begin(); jit != keywordProductMap[it->first].end(); ++jit)
        {
            (**jit).dump(ofile);
        }
    }
}

// std::map<std::string,std::set<Product*>> keywordProductMap;
// std::map<User*,std::queue<Product*>> userCartMap;