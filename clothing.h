#include "product.h"

class Clothing : public Product
{
    public: 
        Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand);
        ~Clothing();
        std::set<std::string> keywords() const;
        std::string displayString() const;
        void dump(std::ostream& os) const;
        bool isMatch(std::vector<std::string>& searchTerms) const;
    protected:
        // extras not in Product
        std::string size_;
        std::string brand_;
};