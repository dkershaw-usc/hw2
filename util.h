#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */

 //REFERENCED https://cplusplus.com/reference/set/set/insert/
 // for iterator syntax
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
    //REFERENCED https://cplusplus.com/reference/set/set/
    //AND https://cplusplus.com/reference/set/set/find/

    //std::set is a sorted container (binary search tree)
    //std::set::find runs in logarithmic time (see reference)

    // iterating through all members of one set will take O(n)
    // together, these will run in O(n*logn)

    std::set<T>* intersectionSet = new std::set<T>;

    //this outer loop runs O(s1->size())
    for (std::set<int>::iterator it = s1->begin(); it != s1->end(); it++)
    {
        //this inner loop runs in O(log(s2.->size()))
        if(s2->find(*it))
        {
            //runs in O(1) since sorted. see https://cplusplus.com/reference/set/set/insert/
            intersectionSet->insert(*it);
        }
    }

    return * intersectionSet;
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
    //Assignment does not define behavior for
    // a union operation on identical/similar sets.
    // I took the liberty of always inserting 
    // no matter what.

    //This function runs in O( s1->size() + s2->size() )
    // or O(2n)
    // or O(n)

    std::set<T>* unionSet = new std::set<T>;

    //this loop runs O(s1->size()), or O(n)
    for(std::set<int>::iterator it = s1->begin(); it != s1->end(); it++)
    {
        unionSet->insert(*it);
    }

    //this loop runs O(s2->size()), or O(n)
    for(std::set<int>::iterator it = s2->begin(); it != s2->end(); it++)
    {
        unionSet->insert(*it);
    }

    return * unionSet;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
