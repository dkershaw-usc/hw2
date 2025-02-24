#include "book.h"
#include "product.h"
#include "util.h"

Book::Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string isbn) :
    Product(category, name, price, qty),
    author_(author),
    isbn_(isbn)
{
}

std::set<std::string> Book::keywords() const
{
    std::set<std::string> out;

    out.insert(convToLower(isbn_));
    std::set<std::string> authorWords = parseStringToWords(author_);
    out.insert(authorWords.begin(), authorWords.end());

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
    std::string p = doubleToCashString(price_);
    std::string q = std::to_string(qty_);
    s += p + ' ' + q + " left.";

    return s;
}

void Book::dump(std::ostream& os) const
{
    os << "book" << '\n';
    os << name_ << '\n';
    os << price_ << '\n';
    os << qty_ << '\n';
    os << isbn_ << '\n';
}

bool Book::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}