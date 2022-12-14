#include "datastore.h"
#include <string>
#include <set>
#include <vector>

class DataBase : public DataStore{
    public:
        DataBase();
        ~DataBase();

        //add items to database
        void addProduct(Product* p);
        void addUser(User* u);
        User* getUser(std::string username) const;

        //edit items in database
        void decreaseStock(Product* p, int num);

        std::vector<Product*> search(std::vector<std::string>& terms, int type);

        void dump(std::ostream& ofile);

        std::set<Product*> products;
        std::set<User*> users;
};