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

int Cart::getSize()
{
    return this->products.size();
}

Product* Cart::get(int index)
{
    return this->products[index];
}