#include "product.h"

class Book : public Product{
    public:
        
    Book() : Product::Product("book", this->name_, this->price_, this->qty_)
    {
    }

    ~Book();

    std::set<std::string> keywords();
    void dump(std::ostream& os);
    std::string displayString();
    private:

};