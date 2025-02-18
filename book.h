#include "product.h"

class Book : public Product
{
    public: 
        Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string isbn);
        ~Book();
        std::set<std::string> keywords() const;
        std::string displayString() const;
        void dump(std::ostream& os) const;
        bool isMatch(std::vector<std::string>& searchTerms) const;
    protected:
        // extras not in Product
        std::string author_;
        std::string isbn_;
};