/*=============================================================================
#     FileName: 214-ShortestPalindrome.cpp
#         Desc: AC, 8ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-01 12:36:05
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        bool isPalindrome(string &s, int l, int r) {
            int deta = 0;
            while (l -deta >= 0) {
                if (s[l - deta] == s[r + deta]) {
                    deta ++;
                } else {
                    return false;
                }
            }
            return true;
        }
        string shortestPalindromeII(string s) {
            int len = s.length(), center = (len - 1) / 2;
            if (len <= 1) {
                return s;
            }
            for (int i = center; i >= 0; i --) {
                if (i + i + 1 < len && isPalindrome(s, i, i + 1)) {
                    string result = s.substr(2 * i + 2, len - 2 * i - 2);
                    result.reserve();
                    result = result + s;
                    return result;
                }
                if (isPalindrome(s, i, i)) {
                    string result = s.substr(2 * i + 1, len - 2 * i - 1);
                    result.reserve();
                    result = result + s;
                    return result;
                }
            }
            return s;
        }
        string shortestPalindrome(string s) {
            string r = s;
            r.reserve();
            string t = s + "#" + r;
            vector<int> p(t.size(), 0);
            for (int i = 1; i < (int)t.size(); i ++) {
                int j = p[i - 1];
                while (j > 0 && t[i] != t[j]) {
                    j = p[j - 1];
                }
                p[i] = (j += t[i] == t[j]);
            }
            return r.substr(0, s.size() - p[t.size() - 1]) + s;
        }

};

int main() {
    Solution solution;
    cout << solution.shortestPalindrome("aacecaaa") << endl;
    cout << solution.shortestPalindrome("abcd") << endl;
    return 0;
}
