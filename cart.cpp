#include "cart.h"

Cart::Cart()
{
    products = new std::vector<Product*>;
}

Cart::~Cart()
{
}

void Cart::add(Product* p)
{
    this->products->push_back(p);
}

void Cart::remove(int index)
{
    this->products->erase(this->products->begin()+index);
}

int Cart::getSize()
{
    return this->products->size();
}

Product* Cart::get(int index)
{
    return this->products->at(index);
}

std::vector<Product*>* Cart::getProducts()
{
    return this->products;
}