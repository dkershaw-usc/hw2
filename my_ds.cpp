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

    switch (type)
    {
    case 1: // OR search
        for(std::vector<std::string>::iterator it = terms.begin(); it != terms.end(); ++it)
        {
            gather.insert(keywordProductMap[*it].begin(), keywordProductMap[*it].end());
        }
        break;
    case 0: // AND search
        // TODO: recursive sol'n:
        // - gather set of term matches from current level
        // - remove elemens not in set intersection of this and next level
        // - when reached base level, return end result

        break;
    default:
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

}

// std::map<std::string,std::set<Product*>> keywordProductMap;
// std::map<User*,std::queue<Product*>> userCartMap;