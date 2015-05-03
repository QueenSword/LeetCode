/*=============================================================================
#     FileName: 76-MinimumWindowSubstring.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-30 07:53:31
#      Version: 0.0.1
#   LastChange: 2015-04-30 09:51:54
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    //40ms
    string minWindow(string s, string t) {
        int len1 = s.length(), len2 = t.length(), count = len2, start = 0, min_len = INT_MAX, min_start = 0;
        if (len1 < len2 || len2 == 0) {
            return "";
        }
        vector<int> count1(256, 0), count2(256, 0);
        for (int i = 0; i < len2; i ++) {
            count1[t[i]] ++;
            count2[t[i]] ++;
        }

        for (int end = 0; end < len1; end ++) {
            if (count2[s[end]] > 0) {
                count1[s[end]] --;
                if (count1[s[end]] >= 0) {
                    count --;
                }
            }
            if (count == 0) {
                while (true) {
                    if (count2[s[start]] > 0) {
                        if (count1[s[start]] < 0) {
                            count1[s[start]] ++;
                        } else {
                            break;
                        }
                    }
                    start ++;
                }
                if (min_len > end - start + 1) {
                    min_len = end - start + 1;
                    min_start = start;
                }
            }
        }

        if (min_len == INT_MAX) {
            return "";
        } else {
            return s.substr(min_start, min_len);
        }
    }
};

int main() {
    Solution solution;
    printf("%s\n", solution.minWindow("bdab", "ab").c_str());

}
