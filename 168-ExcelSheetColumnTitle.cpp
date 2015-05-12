/*=============================================================================
#     FileName: 168-ExcelSheetColumnTitle.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 14:11:30
#      Version: 0.0.1
#   LastChange: 2015-05-12 14:28:12
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <leetcode.h>

class Solution {
public:

    //2ms
    string convertToTitle(int n) {
        string ret = "";
        while (n > 0) {
            n --;
            ret = char(n % 26 + 'A') + ret;
            n /= 26;
        }
        return ret;
    }

};

int main() {
    Solution solution;
    printf("%s\n", solution.convertToTitle(27).c_str());
}

