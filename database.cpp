#include "database.h"

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

void decrementStock(Product* p)
{
    p->subtractQty(1);
}

std::vector<Product*> search(std::vector<std::string>& terms, int type);

void DataBase::dump(std::ostream& ofile)
{
    ofile << "<products>" << "\n";
    for(std::set<Product*>::iterator it = products.begin(); it != products.end(); it++)
    {
        (*it)->dump(ofile);
    }
}