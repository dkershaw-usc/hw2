#include "database.h"
#include "util.h"

DataBase::DataBase()
{
}

DataBase::~DataBase()
{
}

void DataBase::addProduct(Product* p)
{
    //CASE 0: The product exists in the current DataBase
    if(this->products.find(p) == this->products.end())
    {
        return;
    }
    //CASE 1: The product does not exist in the current DataBase
    else
    {
        this->products.insert(p);
    }
}

void DataBase::addUser(User* u)
{
    //CASE 0: The user exists in the current DataBase
    if(this->users.find(u) == this->users.end())
    {
        return;
    }
    //CASE 1: The user does not exist in the current DataBase
    else
    {
        users.insert(u);
    }
}

void DataBase::decreaseStock(Product* p, int num)
{
    p->subtractQty(num);
}

std::vector<Product*> DataBase::search(std::vector<std::string>& terms, int type)
{
    std::vector<Product*> out;
    
    for(std::set<Product*>::iterator it = this->products.begin(); it != this->products.end(); it++)
    {
        bool hasAllTerms = true;
        if(type == 0) //AND search must contain all terms
        {
            for(int i = 0; i < (int) terms.size(); i++)
            {
                //if any of the terms are not in the keywords of a product
                if((*it)->keywords().find(terms[i]) == (*it)->keywords().end())
                {
                    hasAllTerms = false;
                }
            }

            if(hasAllTerms)
            {
                out.push_back(*it);
            }
        }
        else if(type == 1) //OR search must contain one term
        {
            //if any of the terms are found in the keywords
            if((*it)->isMatch(terms))
            {
                //add that product to the output
                out.push_back(*it);
            }
        }
    }

    return out;
}

void DataBase::dump(std::ostream& ofile)
{
    ofile << "<products>" << "\n";
    for(std::set<Product*>::iterator it = products.begin(); it != products.end(); it++)
    {
        (*it)->dump(ofile);
    }
}