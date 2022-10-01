#include "movie.h"
#include "util.h"

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating) : Product::Product("movie", name, price, qty)
{
    this->genre_ = genre;
    this->rating_ = rating;
}

Movie::~Movie()
{
}

void Movie::dump(std::ostream& os) const
{
    //write data from class into raw text stream
    Product::dump(os);
    os << this->genre_ << std::endl;
}

std::set<std::string> Movie::keywords() const
{
    std::set<std::string> s_1 = parseStringToWords(this->name_);
    std::set<std::string> s_2 = parseStringToWords(this->genre_);
    std::set<std::string> s = setUnion(s_1, s_2);
    return s;
}

bool Movie::isMatch(std::vector<std::string>& searchTerms) const
{
    std::set<std::string> k = this->keywords();
    for(int i = 0; i < (int) searchTerms.size(); i++)
    { 
        if(k.find(searchTerms[i]) != k.end()) return true;
    }
    return false;
}

std::string Movie::displayString() const
{
    //The Franchisers 7 | $49.99 | In Stock: 9 | Movie | Action | Rated: R
    std::string out = "";
    out += this->name_;
    out += "| $";
    out += this->price_;
    out += " | In Stock: ";
    out += this->qty_;
    out += " | ";
    out += this->category_;
    out += " | ";
    out += this->genre_;
    out += " | Rated: ";
    out += this->rating_;
    return out;
}