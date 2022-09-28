#include "book.h"
#include "util.h"

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, const std::string author) : Product::Product("book", name, price, qty)
{
    this->isbn_ = isbn;
    this->author_ = author;
}

void Book::dump(std::ostream& os) const
{
    //write data from class into raw text stream
    Product::dump(os);
    os << this->isbn_ <<  "\n" << this->author_ << std::endl;
}

std::set<std::string> Book::keywords()
{
    std::set<std::string> s_1 = parseStringToWords(this->name_);
    std::set<std::string> s_2 = parseStringToWords(this->author_);
    s_1.insert(this->isbn_);
    std::set<std::string> s_3 = setUnion<std::string>(s_1, s_2);
    return s_3;
}

std::string Book::displayString()
{
    //The Kinda Alright Gatsby by Dresden Kershaw | $4.19 | In Stock: 1 | Book
    std::string out = "";
    out += this->name_;
    out += " by ";
    out += this->author_;
    out += "| $";
    out += this->price_;
    out += " | In Stock: ";
    out += this->qty_;
    out += " | ";
    out += this->category_;
    return out;
}