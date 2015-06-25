/*=============================================================================
#     FileName: 85-MaximalRectangle.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-06-19 10:00:30
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), result = 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, 0)));
        dp[0][0][0] = (matrix[0][0] - '0');
        dp[0][0][1] = (matrix[0][0] - '0');
        result = max(result, dp[0][0][0] * dp[0][0][1]);
        for (int i = 1; i < m; i ++) {
            if (matrix[i][0] == '0') {
                continue;
            }
            dp[i][0][0] = dp[i - 1][0][0] + 1;
            dp[i][0][1] = 1;
            result = max(result, dp[i][0][0] * dp[i][0][1]);
        }
        for (int j = 1; j < n; j ++) {
            if (matrix[0][j] == '0') {
                continue;
            }
            dp[0][j][1] = dp[0][j - 1][1] + 1;
            dp[0][j][0] = 1;
            result = max(result, dp[0][j][0] * dp[0][j][1]);
        }

        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
/*                dp[i][j][0] = (int)(matrix[i][j] - '0');*/
                //dp[i][j][1] = (int)(matrix[i][j] - '0');
                if (matrix[i][j] == '1') {
                    dp[i][j][0] = min(dp[i][j - 1][0] - 1, dp[i - 1][j][0]) + 1;
                    dp[i][j][1] = min(dp[i][j - 1][1], dp[i - 1][j][1] - 1) + 1;
                }
                result = max(result, dp[i][j][0] * dp[i][j][1]);
            }
        }
        return result;
    }
};
