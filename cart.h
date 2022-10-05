#include "product.h"
#include <vector>

class Cart{
    public:
        Cart();
        ~Cart();
        void add(Product* product);
        void remove(int index);
        int getSize();
        Product* get(int index);
        std::vector<Product*> getProducts();
        
    private:
        std::vector<Product*> products;
};