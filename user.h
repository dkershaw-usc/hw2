#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include "cart.h"

/**
 * Implements User functionality and information storage
 *  You should not need to derive anything from User at this time
 */
class User {
public:
    User();
    User(std::string name, double balance, int type);
    virtual ~User();

    double getBalance() const;
    std::string getName() const;
    void deductAmount(double amt);
    virtual void dump(std::ostream& os);

    //My Code
    void checkout();
    void addToCart(Product* p);
    Cart* getCart();

private:
    std::string name_;
    double balance_;
    int type_;

    //My Code
    Cart* cart;
};
#endif
