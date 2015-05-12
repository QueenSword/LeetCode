/*=============================================================================
#     FileName: 171-ExcelSheetColumnNumber.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 14:33:20
#      Version: 0.0.1
#   LastChange: 2015-05-12 14:33:20
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    //26ms
    int titleToNumber(string s) {
        int len = s.length(), ret = 0;
        if (len == 0) {
            return 0;
        }
        for (int i = 0; i < len; i ++) {
            ret *= 26;
            ret += (s[i] - 'A') + 1;
        }
        return ret;
    }

};
