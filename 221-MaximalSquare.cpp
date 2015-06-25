/*=============================================================================
#     FileName: 221-MaximalSquare.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-06-19 01:01:02
#      History:
=============================================================================*/


#include <leetcode.h>

class Solution {
public:
    //16ms
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), result = 0;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                dp[i][j] = int(matrix[i][j] - '0');
                if (matrix[i][j] == '1' && i && j) {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
                result = max(result, dp[i][j]);
            }
        }
        return result * result;
    }
};
