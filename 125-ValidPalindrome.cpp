/*=============================================================================
#     FileName: 125-ValidPalindrome.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-09 08:39:16
#      Version: 0.0.1
#   LastChange: 2015-05-09 08:53:27
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    //22ms
    bool isPalindrome(string s) {
        if (s == "") {
            return true;
        }
        transform(s.begin(), s.end(), s.begin(), (int (*)(int))toupper);
        string s1 = "";
        for (int i = 0; i < s.size(); i ++) {
            if ((s[i] >= 'A' & s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
                s1 += s[i];
            }
        }
        int i = 0, j = s1.length() - 1;
        while (i < j) {
            if (s1[i ++] != s1[j --]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    printf("%d\n", solution.isPalindrome("a a"));
}
