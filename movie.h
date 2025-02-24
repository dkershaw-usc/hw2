#include "product.h"

class Movie : public Product
{
    public: 
        Movie(const std::string category, const std::string name, double price, int qty, std::string author, std::string isbn);
        std::set<std::string> keywords() const;
        std::string displayString() const;
        void dump(std::ostream& os) const;
    protected:
        // extras not in Product
        std::string rating_;
        std::string genre_;
};