/*=============================================================================
#     FileName: 10-RegularExpressionMatching.cpp.bak
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-05 01:15:29
#      Version: 0.0.1
#   LastChange: 2015-04-05 01:15:29
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <stdio.h>

using namespace std;

class Solution {
public:

    //29ms
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') {
            return *s == '\0';
        }
        if (*s == '\0') {
            if (*p == '\0') {
                return true;
            }
            if (*(p + 1) == '*') {
                return isMatch(s, p + 2);
            }
            return false;
        }
        

        if (*(p + 1) == '*') {
            if (*p == '.') {
                while (*s != '\0') {
                    if (isMatch(s, p + 2)) {
                        return true;
                    }
                    s ++;
                }
                return isMatch(s, p + 2);
            } else if (*p == *s) {
                while (*p == *s) {
                    if (isMatch(s, p + 2)) {
                        return true;
                    }
                    s ++;
                }
                return isMatch(s, p + 2);
            } else {
                return isMatch(s, p + 2);
            }
        } else {
            return (*s == *p || *p == '.') ? isMatch(s + 1, p + 1) : false;
        }
        return false;
    }
};

int main() {
    
    Solution solution;
   
    cout << solution.isMatch("a", "..a*") << endl;
    return 0; 

}
