/*=============================================================================
#     FileName: 205-IsomorphicStrings.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 20:50:51
#      Version: 0.0.1
#   LastChange: 2015-05-12 20:50:51
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    //127ms
    bool isIsomorphic(string s, string t) {
        int len1 = s.length(), len2 = t.length();
        if (len1 != len2) {
            return false;
        }
        map<char, char> m1, m2;
        for (int i = 0; i < len1; i ++) {
            if (m1.find(s[i]) == m1.end() && m2.find(t[i]) == m2.end()) {
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            } else if (m1.find(s[i]) != m1.end() && m2.find(t[i]) != m2.end()) {
                if (m1[s[i]] != t[i] || m2[t[i]] != s[i]) {
                    return false;
                }

            } else {
                return false;
            }
        }
        return true;
    }
};
