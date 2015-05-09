/*=============================================================================
#     FileName: 131-PalindromePartitioning.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-09 20:34:17
#      Version: 0.0.1
#   LastChange: 2015-05-09 20:45:20
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    //46ms
    void dfs(vector<vector<string> > &result, vector<vector<bool> > &dp, vector<string> ret, string &s, int pos) {
        int len = s.length();
        if (len == pos) {
            result.push_back(ret);
            return ;
        }
        for (int i = pos; i < len; i ++) {
            if (dp[pos][i]) {
                ret.push_back(s.substr(pos, i - pos + 1));
                dfs(result, dp, ret, s, i + 1);
                ret.pop_back();
            }
        }
        return ;
    }

    vector<vector<string> > partition(string s) {
        vector<vector<string> > result;
        int len = s.length();
        if (len == 0) {
            return result;
        }
        vector<vector<bool> > dp(len, vector<bool>(len, false));
        for (int i = 0; i < len; i ++) {
            for (int j = 0; j <= i; j ++) {
                if (i == j) {
                    dp[j][i] = true;
                } else if (i - j == 1) {
                    dp[j][i] = s[i] == s[j];
                } else {
                    dp[j][i] = (s[i] == s[j] && dp[j + 1][i - 1]);
                }
            }
        }
        vector<string> ret;
        dfs(result, dp, ret, s, 0);
        return result;
    }
};
