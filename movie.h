

#include "product.h"

class Movie : Product
{
    public: 
        std::set<std::string> keywords() const;
        std::string displayString() const;
        void dump(std::ostream& os) const;
    protected:
        // extras not in Product
        std::string genre_;
        std::string rating_;
};