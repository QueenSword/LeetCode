/*=============================================================================
#     FileName: 174-DungeonGame.cpp
#         Desc: AC, 16ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-01 09:35:43
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int calculateMinimumHP(vector<vector<int> >& dungeon) {
            int m = dungeon.size(), n = dungeon[0].size();
            vector<vector<int> > info(m, vector<int>(n, 0));
            info[m - 1][n - 1] = dungeon[m - 1][n - 1] >= 0 ? 0 : -dungeon[m - 1][n - 1];
            for (int i = m - 2; i > -1; i --) {
                info[i][n - 1] = dungeon[i][n - 1] >= info[i + 1][n - 1] ? 0 : info[i + 1][n - 1] - dungeon[i][n - 1];
            }
            for (int i = n - 2; i > -1; i --) {
                info[m - 1][i] = dungeon[m - 1][i] >= info[m - 1][i + 1] ? 0 : info[m - 1][i + 1] - dungeon[m - 1][i];
            }

            for (int i = m - 2; i > -1; i --) {
                for (int j = n - 2; j > -1; j --) {
                    int down = dungeon[i][j] >= info[i + 1][j] ? 0 : info[i + 1][j] - dungeon[i][j];
                    int right = dungeon[i][j] >= info[i][j + 1] ? 0 : info[i][j + 1] - dungeon[i][j];
                    info[i][j] = min(down, right);
                }
            }
            return info[0][0] + 1;
        }
};

