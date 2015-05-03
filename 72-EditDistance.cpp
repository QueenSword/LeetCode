/*=============================================================================
#     FileName: 72-EditDistance.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-29 23:05:37
#      Version: 0.0.1
#   LastChange: 2015-04-29 23:05:37
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    //43ms
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        if (l1 * l2 == 0) {
            return max(l1, l2);
        }
        vector<vector<int> > dp(l1 + 1, vector<int>(l2 + 1, 0));
        for (int i = 0; i <= l1; i ++) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= l2; i ++) {
            dp[0][i] = i;
        }
        
        for (int i = 1; i <= l1; i ++) {
            for (int j = 1; j <= l2; j ++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[l1][l2];
    }
};
