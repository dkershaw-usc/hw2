#include "cart.h"

Cart::Cart()
{
}

Cart::~Cart()
{
}

void Cart::add(Product* product)
{
    this->products.push_back(product);
}

void Cart::remove(int index)
{
    this->products.erase(this->products.begin()+index);
}

int Cart::getSize()
{
    return this->products.size();
}

Product* Cart::get(int index)
{
    return this->products[index];
}

std::vector<Product*> Cart::getProducts()
{
    return this->products;
}