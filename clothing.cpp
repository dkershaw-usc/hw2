#include "clothing.h"
#include "util.h"
#include <iostream>
#include <iomanip>
#include <sstream>

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand) : Product::Product("clothing", name, price, qty)
{
    this->size_ = size;
    this->brand_ = brand;
}

Clothing::~Clothing()
{
}

void Clothing::dump(std::ostream& os) const
{
    //write data from class into raw text stream
    Product::dump(os);
    os << this->size_ << "\n" << this->brand_ << std::endl;
}

std::set<std::string> Clothing::keywords() const
{
    //parse the item name and brand into words
    std::set<std::string> s_1 = parseStringToWords(this->name_);
    std::set<std::string> s_2 = parseStringToWords(this->brand_);
    //combine these into a comprehensive list
    // of keywords
    std::set<std::string> s_3 = setUnion<std::string>(s_1, s_2);
    return s_3;
}

bool Clothing::isMatch(std::vector<std::string>& searchTerms) const
{
    std::set<std::string> k = this->keywords();
    for(int i = 0; i < (int) searchTerms.size(); i++)
    { 
        if(k.find(searchTerms[i]) != k.end()) return true;
    }
    return false;
}

std::string Clothing::displayString() const
{
    //Men's Performance Scarf by Nike | $29.98 | In Stock: 2 | Clothing | Size: Medium 
    std::stringstream outStream;
    outStream << this->name_;
    outStream << " by ";
    outStream << this->brand_;
    outStream << "| $";
    outStream << std::setprecision(4) << this->price_;
    outStream << " | In Stock: ";
    outStream << std::to_string(this->qty_);
    outStream << " | ";
    outStream << "Clothing";
    std::string out = outStream.str();
    return out;
}