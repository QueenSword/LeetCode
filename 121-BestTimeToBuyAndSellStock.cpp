/*=============================================================================
#     FileName: 121-BestTimeToBuyAndSellStock.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-08 20:27:54
#      Version: 0.0.1
#   LastChange: 2015-05-08 20:27:54
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    //12ms
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), result = 0;
        if (n < 2) {
            return 0;
        }
        vector<int> min_val(n, prices[0]);
        for (int i = 1; i < n; i ++) {
            min_val[i] = min(prices[i], min_val[i - 1]);
        }
        for (int i = 0; i < n; i ++) {
            result = max(result, prices[i] - min_val[i]);
        }
        return result;
    }

};
