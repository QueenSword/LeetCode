/*=============================================================================
#     FileName: 132-PalindromePartitioningII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-09 20:46:34
#      Version: 0.0.1
#   LastChange: 2015-05-09 21:04:21
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
public:
    //135ms
    int minCut(string s) {
        int len = s.length();
        if (len == 0 || len == 1) {
            return 0;
        }
        vector<vector<bool> > is_palindrome(len, vector<bool>(len, false));
        vector<int> min_cut(len, INT_MAX);
        for (int i = 0; i < len; i ++) {
            for (int j = 0; j <= i; j ++) {
                if (s[i] == s[j] && (i - j < 3 || is_palindrome[j + 1][i - 1])) {
                    is_palindrome[j][i] = true;
                }
            }
        }

        for (int i = 0; i < len; i ++) {
            if (is_palindrome[0][i]) {
                min_cut[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j ++) {
                if (is_palindrome[j + 1][i]) {
                    min_cut[i] = min(min_cut[j] + 1, min_cut[i]);
                }
            }
        }
        return min_cut[len - 1];
    }
};
