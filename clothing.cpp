#include "clothing.h"
#include "util.h"

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand) : Product::Product("clothing", name, price, qty)
{
    this->size_ = size;
    this->brand_ = brand;
}

void Clothing::dump(std::ostream& os) const
{
    //write data from class into raw text stream
    Product::dump(os);
    os << this->size_ << "\n" << this->brand_ << std::endl;
}

std::set<std::string> Clothing::keywords()
{
    //parse the item name and brand into words
    std::set<std::string> s_1 = parseStringToWords(this->name_);
    std::set<std::string> s_2 = parseStringToWords(this->brand_);
    //combine these into a comprehensive list
    // of keywords
    std::set<std::string> s_3 = setUnion<std::string>(s_1, s_2);
    return s_3;
}

std::string Clothing::displayString()
{
    //Men's Performance Scarf by Nike | $29.98 | In Stock: 2 | Clothing | Size: Medium 
    std::string out = "";
    out += this->name_;
    out += " by ";
    out += this->brand_;
    out += "| $";
    out += this->price_;
    out += " | In Stock: ";
    out += this->qty_;
    out += " | ";
    out += this->category_;
    out += " | Size: ";
    out += this->size_;
    return out;
}