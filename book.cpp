#include "book.h"
#include "util.h"
#include <iostream>
#include <iomanip>
#include <sstream>

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, const std::string author) : Product::Product("book", name, price, qty)
{
    this->isbn_ = isbn;
    this->author_ = author;
}

Book::~Book()
{
}

void Book::dump(std::ostream& os) const
{
    //write data from class into raw text stream
    Product::dump(os);
    os << this->isbn_ <<  "\n" << this->author_ << std::endl;
}

bool Book::isMatch(std::vector<std::string>& searchTerms) const
{
    std::set<std::string> k = this->keywords();
    for(int i = 0; i < (int) searchTerms.size(); i++)
    { 
        if(k.find(searchTerms[i]) != k.end()) return true;
    }
    return false;
}

std::set<std::string> Book::keywords() const
{
    std::set<std::string> s_1 = parseStringToWords(this->name_);
    std::set<std::string> s_2 = parseStringToWords(this->author_);
    s_1.insert(this->isbn_);
    std::set<std::string> s_3 = setUnion<std::string>(s_1, s_2);
    return s_3;
}

std::string Book::displayString() const
{
    //The Decent Gatsby by Dresden Kershaw | $4.19 | In Stock: 1 | Book
    std::stringstream outStream;
    outStream << this->name_;
    outStream << " by ";
    outStream << this->author_;
    outStream << " | $";
    outStream << std::setprecision(4) << this->price_;
    outStream << " | In Stock: ";
    outStream << std::to_string(this->qty_);
    outStream << " | ";
    outStream << "Book";
    std::string out = outStream.str();
    return out;
}
