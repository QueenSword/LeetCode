/*=============================================================================
#     FileName: 70-ClimbingStairs.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-29 22:28:13
#      Version: 0.0.1
#   LastChange: 2015-04-29 22:28:13
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:

    //2ms
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        } else {
            vector<int> dp(n, 0);
            dp[0] = 1;
            dp[1] = 2;
            for (int i = 2; i < n; i ++) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n - 1];
        }
    }

};
