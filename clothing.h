

#include "product.h"

class Clothing : Product
{
    public: 
        std::set<std::string> keywords() const;
        bool isMatch(std::vector<std::string>& searchTerms) const;
        std::string displayString() const;
        void dump(std::ostream& os) const;
    protected:
        // extras not in Product
        std::string size;
        std::string brand;
};