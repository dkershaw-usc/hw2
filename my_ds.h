#include "datastore.h"
#include "util.h"
#include <map>
#include <queue>

class MyDataStore : DataStore
{
    public:
        void addProduct(Product *p);
        void addUser(User *u);
        std::vector<Product*> search(std::vector<std::string>& terms, int type);
        void dump(std::ostream& ofile);
    protected:
        std::map<std::string,std::set<Product*>> keywordProductMap;
        std::map<User*,std::queue<Product*>> userCartMap;
};