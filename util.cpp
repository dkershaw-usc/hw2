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
    std::set<std::string>* s = new std::set<std::string>;
    std::string buf = "";

    for(int i = 0; i < (int) rawWords.length(); i++)
    {
        buf += rawWords[i];
        bool needsCleared = false;

        //CASE 0: string has no punctuation
        if(rawWords[i] == ' ')
        {
            needsCleared = true;
        }
        //CASE 1: string contains punctuation
        // the current character is not a number or letter 
        //  (not alphanumeric)
        else if (!std::isalnum(rawWords[i]))
        {
            needsCleared = true;
        }

        //clear the string buffer
        if(needsCleared)
        {
            //the last index is either whitespace or 
            // non-alphanumeric; thus, pop its last index
            buf.pop_back();
            //if string is 2 or more, add to keywords
            if (buf.length() > 1)
            {
                s->insert(convToLower(buf));
            }
            //either way, clear the buffer of the current word
            buf.clear();
        }
    }
    
    return * s;
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
