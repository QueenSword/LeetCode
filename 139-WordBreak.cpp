/*=============================================================================
#     FileName: 139-WordBreak.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-10 08:43:09
#      Version: 0.0.1
#   LastChange: 2015-05-10 08:53:18
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    //15ms
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.length();
        if (len < 0) {
            return true;
        }

        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for (int i = 1; i <= len; i ++) {
            for (int j = 0; j < i; j ++) {
                if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];

    }
};

int main() {
    unordered_set<string> dict;
    Solution solution;
    printf("%d\n", solution.wordBreak("a", dict));
}
