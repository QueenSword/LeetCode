/*=============================================================================
#     FileName: 63-UniquePathsII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-29 13:38:54
#      Version: 0.0.1
#   LastChange: 2015-04-29 14:07:36
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    //time limit exceeded
    /*void dfs(int i, int j, int m, int n, vector<vector<int> > obstacleGrid) {
        if (i == m - 1) {
            bool has_obstacle = false;
            for (int k = j + 1; k < n; k ++) {
                if (obstacleGrid[i][k]) {
                    has_obstacle = true;
                    break;
                }
            }
            if (!has_obstacle) {
                ret ++;
            }
            return ;
        }
        if (j == n - 1) {
            bool has_obstacle = false;
            for (int k = i + 1; i < m; i ++) {
                if (obstacleGrid[k][j]) {
                    has_obstacle = true;
                    break;
                }
            }
            if (!has_obstacle) {
            ret ++;
            }
            return ;
        }
        if (i < m - 1 && obstacleGrid[i + 1][j] != 1) {
            dfs(i + 1, j, m, n, obstacleGrid);
        }
        if (j < n - 1 && obstacleGrid[i][j + 1] != 1) {
            dfs(i, j + 1, m, n, obstacleGrid);
        }
    }*/
    
    //10ms
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[0][0] = obstacleGrid[0][0] ? 0 : 1;
        for (int i = 1; i < n; i ++) {
            dp[0][i] = obstacleGrid[0][i] ? 0 : dp[0][i - 1];
        }
        for (int i = 1; i < m; i ++) {
            dp[i][0] = obstacleGrid[i][0] ? 0 : dp[i - 1][0];
        }
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

