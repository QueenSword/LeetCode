/*=============================================================================
#     FileName: 198-HouseRobber.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-15 13:02:19
#      Version: 0.0.1
#   LastChange: 2015-04-15 13:02:20
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //2ms
    int rob(vector<int> &num) {
        if (num.empty()) {
            return 0;
        }
        int len = num.size();
        if (len == 1) {
            return num[0];
        }
        if (len == 1) {
            return max(num[0], num[1]);
        }
        vector<int> dp(len, num[0]);
        dp[1] = max(dp[0], num[1]);
        for (int i = 2; i < len; i ++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + num[i]);
        }
        return dp[len - 1];

    }
};

int main() {
    
    return 0;
}
