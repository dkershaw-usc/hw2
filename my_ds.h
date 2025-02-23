#include <map>
#include <queue>

#include "datastore.h"
#include "util.h"

// "product.h" provided by "datastore.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"

class MyDataStore : public DataStore
{
    public:
        void addProduct(Product *p);
        void addUser(User *u);
        std::vector<Product*> search(std::vector<std::string>& terms, int type);
        void dump(std::ostream& ofile);
        std::set<Product*>& getProductsForKeyword(std::string term);
        void addToCart(std::string username, Product*);
        void viewCart(std::string username);
        // Must preserve order added to cart. FIFO.
        void buyCart(std::string username);
        void tryBuy(User* u,Product* p);
        User* findUserByName(std::string);
    protected:
        std::map<std::string,std::set<Product*>> keywordProductMap;
        std::map<User*,std::vector<Product*>> userCartMap;
};