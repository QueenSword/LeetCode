/*=============================================================================
#     FileName: 28-ImplementStrStr.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-06 23:54:13
#      Version: 0.0.1
#   LastChange: 2015-04-06 23:54:13
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <leetcode.h>


class Solution {
public:
    
    void getNext(vector<int> &next, string &needle) {
        int len = needle.length();
        int k = -1, j = 0;
        next[0] = k;
        while (j < len - 1) {
            if (k == -1 || needle[j] == needle[k]) {
                k ++;
                j ++;
                next[j] = k;
            } else {
                k = next[k];
            }
        }
    }
    //4ms
    int strStr(string haystack, string needle) {
        int len1 = haystack.length(), len2 = needle.length();
        if (len1 < len2) {
            return -1;
        }
        if (len2 == 0) {
            return 0;
        }
        vector<int> next(len2, 0);
        getNext(next, needle);
        cout << endl;
        int i = 0, j = 0;
        while (i < len1 && j < len2) {
            if (j == -1 || haystack[i] == needle[j]) {
                i ++;
                j ++;
            } else {
                j = next[j];
            }
        }
        if (j == len2) {
            return i - j;
        }
        return -1;

    }
};
    
int main() {
    Solution solution;
    cout << solution.strStr("aaa", "aa") << endl;
    return 0;
}
