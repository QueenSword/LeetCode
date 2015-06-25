/*=============================================================================
#     FileName: 188-BestTimeToBuyAndSellStockIV.cpp
#         Desc: AC 8ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-06-25 16:50:39
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len == 0) {
            return 0;
        }

        if (k >= len) {
            int profit = 0;
            for (int i = 0; i < len - 1; i ++) {
                profit = max(profit, profit + prices[i + 1] - prices[i]);
            }
            return profit;
        }
        

        vector<int> global(k + 1, 0), local(k + 1, 0);
        
        for (int i = 0; i < len - 1; i ++) {
            int diff = prices[i + 1] - prices[i];
            for (int j = k; j >= 1; j --) {
                local[j] = max(local[j] + diff, global[j - 1] + max(0, diff));
                global[j] = max(global[j], local[j]);
            }
        }
        return global[k];
    }


};
