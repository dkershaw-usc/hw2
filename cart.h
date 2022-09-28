#include "product.h"
#include <vector>

class Cart{
    public:
        Cart();
        ~Cart();
        void add(Product* product);
        int getSize();
        Product* get(int index);
        
    private:
        std::vector<Product*> products;
};