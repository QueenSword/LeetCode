/*=============================================================================
#     FileName: 120-Triangle.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-08 20:00:50
#      Version: 0.0.1
#   LastChange: 2015-05-08 20:25:46
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    //17ms
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty() || triangle[0].empty()) {
            return 0;
        }
        int n = triangle.size();
        if (n == 1) {
            return triangle[0][0];
        }
        vector<vector<int> > dp(n, vector<int>(n, triangle[0][0]));
        dp[1][0] += triangle[1][0];
        dp[1][1] += triangle[1][1];
        for (int i = 2; i < n; i ++) {
            for (int j = 0; j < i + 1; j ++) {
                if (j == 0) {
                    dp[i][j] = triangle[i][j] + dp[i - 1][j];
                } else if (j == i) {
                    dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
                }
            }
        }
        int result = dp[n - 1][0];
        for (int i = 0; i < n; i ++) {
            result = min(result, dp[n - 1][i]);
        }
        return result;
    }

};
