#include "product.h"

class Clothing : public Product{
    public:
        
    Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand);
    ~Clothing();

    std::set<std::string> keywords() const;
    void dump(std::ostream& os) const;
    std::string displayString() const;

    bool isMatch(std::vector<std::string>& searchTerms) const;
    
    private:
    std::string brand_;
    std::string size_;
};