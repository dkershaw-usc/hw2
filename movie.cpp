#include "Movie.h"
#include "util.h"

std::set<std::string> Movie::keywords() const
{
    std::set<std::string> out;

    out.insert(genre_);
    out.insert(rating_);

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
    std::string p = std::to_string(price_);
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
    os << "Oops! This is a placeholder!\n";
}