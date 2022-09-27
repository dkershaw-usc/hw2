#include "book.h"

void Book::dump(std::ostream& os)
{
    ;
}

std::set<std::string> Book::keywords()
{
    std::set<std::string>* s = new std::set<std::string>;
    s->insert(this->name_);
    s->insert(std::to_string(this->price_));
    s->insert(std::to_string(this->qty_));
    s->insert(this->category_);
    return * s;
}

std::string Book::displayString()
{
    std::string out = "";
    out += this->name_;
    out += "| $";
    out += this->price_;
    out += " | In Stock: ";
    out += this->qty_;
    out += " | ";
    out += this->category_;
    return out;
}