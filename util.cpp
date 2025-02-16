#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    rawWords = trim(rawWords);
    
    std::set<std::string> parsedOutput;
    size_t substrBegin = 0;
    size_t substrEnd = 0;

    for(std::string::iterator it = rawWords.begin(); it != rawWords.end(); ++it)
    {
        // if current index is a valid character
        if(std::isalnum(*it))
        {
            substrEnd++;
        }
        else
        {
            // grab substring 
            std::string s = rawWords.substr(substrBegin, substrEnd);
            // put it in our output set
            if(s.length() >= 2) parsedOutput.insert(s);
            // reset tracking
            substrBegin += substrEnd + 1;
            substrEnd = 0;
        }

        // tail case
        if(substrBegin + substrEnd == rawWords.length())
        {
            // grab substring 
            std::string s = rawWords.substr(substrBegin, substrEnd);
            // put it in our output set
            if(s.length() >= 2) parsedOutput.insert(s);
        }
    }
    return parsedOutput;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
