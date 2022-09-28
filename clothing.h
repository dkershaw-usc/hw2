#include "product.h"

class Clothing : public Product{
    public:
        
    Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand);
    ~Clothing();

    std::set<std::string> keywords();
    void dump(std::ostream& os) const;
    std::string displayString();
    
    private:
    std::string brand_;
    std::string size_;
};