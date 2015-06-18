/*=============================================================================
#     FileName: 213-HouseRobberII.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-06-18 10:49:30
#      Version: 0.0.1
#   LastChange: 2015-06-18 11:48:06
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //4ms
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return nums[0];
        }
        if (len == 2) {
            return max(nums[0], nums[1]);
        }
        if (len ==3) {
            return max(max(nums[0], nums[1]), nums[2]);
        }
        vector<vector<int> > dp(len, vector<int>(2, 0));
        dp[0][0] = nums[0];
        dp[0][1] = 0;
        dp[1][0] = nums[0];
        dp[1][1] = nums[1];

        for (int i = 2; i < len - 1; i ++) {
            dp[i][0] = max(nums[i] + dp[i - 2][0], dp[i - 1][0]);
            dp[i][1] = max(nums[i] + dp[i - 2][1], dp[i - 1][1]);
        }
        dp[len - 1][0] = dp[len - 2][0];
        dp[len - 1][1] = max(nums[len - 1] + dp[len - 3][1], dp[len - 2][1]);
        return max(dp[len - 1][0], dp[len - 1][1]);
    }
};

int main() {
    int nums[] = {1,1,3,6,7,10,7,1,8,5,9,1,4,4,3};
    vector<int> vec;
    for (int i = 0; i < sizeof(nums) / sizeof(int); i ++) {
        vec.push_back(nums[i]);
    }
    Solution solution;
    cout << solution.rob(vec) << endl;
    return 0;
}
