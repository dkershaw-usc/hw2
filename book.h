

#include "product.h"

class Book : Product
{
    public: 
        std::set<std::string> keywords() const;
        std::string displayString() const;
        void dump(std::ostream& os) const;
    protected:
        // extras not in Product
        std::string isbn_;
        std::string author_;
};