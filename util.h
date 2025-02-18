#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>
#include <functional>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
    // define new not to overwrte args
    typename std::set<T> insxResult;
    // iterates over n elements of s1
    for(typename std::set<T>::iterator it = s1.begin(); it != s1.end(); ++it)
    {
        // set::find runs O(logn), reference: https://cplusplus.com/reference/set/set/find/
        typename std::set<T>::iterator found = s2.find(*it);
        if(found != s2.end()) 
        {
            insxResult.insert(*it);
        }
        else
        {
            insxResult.erase(*it);
        }
    }
    return insxResult;
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
    // don't overwrite args
    typename std::set<T> unxResult = s1;
    // iterates over n elements of s2
    for(typename std::set<T>::iterator it = s2.begin(); it != s2.end(); ++it)
    {
        // set::find runs O(logn), reference: https://cplusplus.com/reference/set/set/find/
        typename std::set<T>::iterator found = s1.find(*it);
        if(found == s1.end()) unxResult.insert(*it);
    }
    return unxResult;
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
