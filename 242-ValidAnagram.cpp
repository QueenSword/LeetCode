/*=============================================================================
#     FileName: 242-ValidAnagram.cpp
#         Desc: AC, 12ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-01 14:17:59
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int len = s.length();
        vector<int> count(26, 0);
        for (int i = 0; i < len; i ++) {
            count[s[i] - 'a'] --;
            count[t[i] - 'a'] ++;
        }
        for (int i = 0; i < 26; i ++) {
            if (count[i] != 0) {
                return false;
            }
        }
        return true;
    }

};

