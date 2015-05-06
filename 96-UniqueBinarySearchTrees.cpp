/*=============================================================================
#     FileName: 96-UniqueBinarySearchTrees.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-04 20:08:56
#      Version: 0.0.1
#   LastChange: 2015-05-04 20:35:55
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    //1ms
    int numTrees(int n) {
        if (n < 3) {
            return n;
        }
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; i ++) {
            dp[i] = 0;
            for (int j = 0; j < i; j ++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
