#include "clothing.h"
#include "util.h"

std::set<std::string> Clothing::keywords() const
{
    std::set<std::string> out;

    out.insert(brand_);
    out.insert(size_);

    std::set<std::string> nameWordSet = parseStringToWords(getName());
    // inserting a set into a set req's iterator params
    out.insert(nameWordSet.begin(), nameWordSet.end());

    return out;
}

std::string Clothing::displayString() const
{
    std::string s;

    s += name_ + '\n';
    s += "Size: " + size_ + " Brand: " + brand_ + '\n';
    std::string p = std::to_string(price_);
    std::string q = std::to_string(qty_);
    s += p + ' ' + q + " left." + '\n';

    return s;
}

void Clothing::dump(std::ostream& os) const
{
    os << "clothing" << '\n';
    os << name_ << '\n';
    os << price_ << '\n';
    os << qty_ << '\n';
    os << size_ << '\n';
    os << brand_ << '\n';
    os << "Oops! This is a placeholder!\n";
}