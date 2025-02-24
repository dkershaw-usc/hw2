#include "movie.h"
#include "util.h"

Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating) :
    Product(category, name, price, qty),
    genre_(genre),
    rating_(rating)
{
}

std::set<std::string> Movie::keywords() const
{
    std::set<std::string> out;

    out.insert(convToLower(genre_));
    out.insert(convToLower(rating_));

    std::set<std::string> nameWordSet = parseStringToWords(getName());
    // inserting a set into a set req's iterator params
    out.insert(nameWordSet.begin(), nameWordSet.end());

    return out;
}

std::string Movie::displayString() const
{
    std::string s;

    s += name_ + '\n';
    s += "Genre: " + genre_ + " Rating: " + rating_ + '\n';
    std::string p = doubleToCashString(price_);
    std::string q = std::to_string(qty_);
    s += p + ' ' + q + " left." + '\n';

    return s;
}

void Movie::dump(std::ostream& os) const
{
    os << "movie" << '\n';
    os << name_ << '\n';
    os << price_ << '\n';
    os << qty_ << '\n';
    os << rating_ << '\n';
    os << genre_ << '\n';
}