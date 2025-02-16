#include "book.h"
#include "util.h"

std::set<std::string> Book::keywords() const
{
    std::set<std::string> out;

    out.insert(isbn_);
    out.insert(author_);

    std::set<std::string> nameWordSet = parseStringToWords(getName());
    // inserting a set into a set req's iterator params
    out.insert(nameWordSet.begin(), nameWordSet.end());

    return out;
}

std::string Book::displayString() const
{
    std::string s;

    s += name_ + '\n';
    s += "Author: " + author_ + " ISBN: " + isbn_ + '\n';
    std::string p = std::to_string(price_);
    std::string q = std::to_string(qty_);
    s += p + ' ' + q + " left." + '\n';

    return s;
}

void Book::dump(std::ostream& os) const
{
    os << "book" << '\n';
    os << name_ << '\n';
    os << price_ << '\n';
    os << qty_ << '\n';
    os << isbn_ << '\n';
    os << "Oops! This is a placeholder!\n";
}