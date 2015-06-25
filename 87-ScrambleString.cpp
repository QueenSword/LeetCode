/*=============================================================================
#     FileName: 87-ScrambleString.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-06-19 11:00:20
#      History:
=============================================================================*/


#include <leetcode.h>

class Solution {
public:
    //8ms
    bool isScramble(string s1, string s2) {
        int len = s1.length(), len2 = s2.length(), alpha = 26;
        if (len != len2) {
            return false;
        }
        if (s1 == s2) {
            return true;
        }
        vector<int> count(alpha, 0);
        for (int i = 0; i < len; i ++) {
            count[s1[i] - 'a'] ++;
            count[s2[i] - 'a'] --;
        }
        for (int i = 0; i < alpha; i ++) {
            if (count[i] != 0) {
                return false;
            }
        }
        for (int i = 1; i < len; i ++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i))) {
                return true;
            }
        }
        return false;
    }
};
