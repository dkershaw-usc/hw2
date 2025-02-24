#include "clothing.h"
#include "product.h"
#include "util.h"

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand) :
    Product(category, name, price, qty),
    size_(size),
    brand_(brand)
{
}

std::set<std::string> Clothing::keywords() const
{
    std::set<std::string> out;

    std::set<std::string> brandWords = parseStringToWords(brand_);
    out.insert(brandWords.begin(), brandWords.end());
    out.insert(convToLower(size_));

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
    std::string p = doubleToCashString(price_);
    std::string q = std::to_string(qty_);
    s += p + ' ' + q + " left.";

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
}

bool Clothing::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}