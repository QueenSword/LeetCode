/*=============================================================================
#     FileName: 122-BestTimeToBuyAndSellStockII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-08 20:52:50
#      Version: 0.0.1
#   LastChange: 2015-05-08 21:00:51
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
            return result;
        }
        int start = 0, end;
        while (true) {
            while (start < n - 1 && prices[start + 1] <= prices[start]) {
                start ++;
            }
            end = start;
            while (end < n - 1 && prices[end + 1] >= prices[end]) {
                end ++;
            }
            if (end == n - 1) {
                return result + max(prices[end] - prices[start], 0);
            }
            result += prices[end] - prices[start];
            start = end;
        }
    }

};
