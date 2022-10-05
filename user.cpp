#include "user.h"
using namespace std;

User::User() : name_("unknown"), balance_(0.0), type_(1), cart()
{

}
User::User(std::string name, double balance, int type) :
    name_(name), balance_(balance), type_(type), cart()
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
        //CASE 0: bad username. handled in amazon.cpp
        //CASE 1: Item is in stock and can be afforded by the user
        if(this->cart.get(i)->getPrice() < this->balance_ && this->cart.get(i)->getQty() > 0)
        {
            this->balance_ -= this->cart.get(i)->getPrice();
            this->cart.remove(i);
        }
        //CASE 2: Purchase unsuccessful, iterates to next product in cart
    }
}

void User::addToCart(Product* p)
{
    this->cart.add(p);
}

Cart* User::getCart()
{
    return &this->cart;
}