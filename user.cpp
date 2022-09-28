#include "user.h"
using namespace std;

User::User() : name_("unknown"), balance_(0.0), type_(1)
{

}
User::User(std::string name, double balance, int type) :
    name_(name), balance_(balance), type_(type)
{

}

User::~User()
{

}


std::string User::getName() const
{
    return name_;
}

double User::getBalance() const
{
    return balance_;
}

void User::deductAmount(double amt)
{
    balance_ -= amt;
}

void User::dump(std::ostream& os)
{
    os << name_ << " "  << balance_ << " " << type_ << endl;
}

//My Code
void User::checkout()
{
    for(int i = this->cart.getSize() - 1; i >= 0; i--)
    {
        //CASE 0: Item is out of stock
        //CASE 1: Cannot afford item
        //CASE 2: Purchase successful
    }
}