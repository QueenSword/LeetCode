/*=============================================================================
#     FileName: 161-OneEditDistance.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-06-25 21:43:52
#      History:
=============================================================================*/


#include <leetcode.h>

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int len1 = s.length(), len2 = t.length();
        if (abs(len1 - len2) > 1) {
            return false;
        }
        if (len1 == len2) {
            if (s == t) {
                return false;
            }
            int count = 0;
            for (int i = 0; i < len1; i ++) {
                if (s[i] != t[i]) {
                    if (count) {
                        return false;
                    }
                    count ++;
                }
            }
            return true;
        }
        if (len1 + 1 == len2) {
            s.swap(t);
        }
        int pos = 0;
        while (pos < len2) {
            if (s[pos] != t[pos]) {
                break;
            }
            pos ++;
        }
        if (pos == len2) {
            return false;
        }
        for (int i = pos; i < len2; i ++) {
            if (s[i + 1] != t[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.isOneEditDistance("abc", "abc") << endl;
    cout << solution.isOneEditDistance("abc", "abcd") << endl;
    cout << solution.isOneEditDistance("abc", "adbc") << endl;
    cout << solution.isOneEditDistance("abc", "absdc") << endl;
    cout << solution.isOneEditDistance("absc", "abc") << endl;
    cout << solution.isOneEditDistance("acc", "abc") << endl;
    return 0;
}
