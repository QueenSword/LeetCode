/*=============================================================================
#     FileName: 64-MinimumPathSum.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-29 14:08:40
#      Version: 0.0.1
#   LastChange: 2015-04-29 14:25:22
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    //21ms
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, grid[0][0]));
        for (int i = 1; i < n; i ++) {
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        }
        for (int i = 1; i < m; i ++) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }
        
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int> > vec(2, vector<int>(2, 1));
    vec[0][1] = 2;
    Solution solution;
    printf("%d\n", solution.minPathSum(vec));
}
