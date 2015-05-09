/*=============================================================================
#     FileName: 123-BestTimeToBuyAndSellStockIII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-08 21:01:41
#      Version: 0.0.1
#   LastChange: 2015-05-09 07:53:04
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    //27ms
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), result = 0;
        if (n < 2) {
            return result;
        }
        vector<int> left_min(n), left_profit(n), right_max(n), right_profit(n);
        for (int i = 0; i < n; i ++) {
            left_min[i] = (i == 0 ? prices[i] : min(left_min[i - 1], prices[i]));
            left_profit[i] = (i == 0 ? prices[i] - left_min[i] : max(left_profit[i - 1], prices[i] - left_min[i]));
        }
        for (int i = n - 1; i >= 0; i --) {
            right_max[i] = (i == n - 1 ? prices[i] : max(right_max[i + 1], prices[i]));
            right_profit[i] = (i == n - 1 ? right_max[i] - prices[i] : max(right_profit[i + 1], right_max[i] - prices[i]));
        }
        result = max(left_profit[n - 1], right_profit[0]);
        for (int i = 1; i < n - 1; i ++) {
            result = max(left_profit[i] + right_profit[i + 1], result);
        }
        return result;

    }

};

int main() {
    int nums[] = {3,2,6,5,0,3};
    vector<int> prices;
    for (int i = 0; i < sizeof(nums) / sizeof(int); i ++) {
        prices.push_back(nums[i]);
    }
    Solution solution;
    printf("%d\n", solution.maxProfit(prices));

}
