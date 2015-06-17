/*=============================================================================
#     FileName: 200-NumberOfIslands.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-10 14:34:14
#      Version: 0.0.1
#   LastChange: 2015-04-10 14:34:14
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>

using namespace std;

struct Position {
    int x;
    int y;
    Position(int _y, int _x) {
        y = _y;
        x = _x;
    }
};

class Solution {
public:
    bool isLegal(vector<vector<char> > &grid, int m, int n, int y, int x) {
        if (y < 0 || y >= m || x < 0 || x >= n || grid[y][x] == '0') {
            return false;
        }
        return true;
    }

    void dfs(vector<vector<char>> &grid, Position pos) {
        int m = grid.size(), n = grid[0].size();
        int direction[4][2] = {
                            {1, 0}, 
                            {-1, 0}, 
                            {0, -1},
                            {0, 1}};
        for (int i = 0; i < 4; i ++) {
            Position next(pos.y + direction[i][1], pos.x + direction[i][0]);
            if (isLegal(grid, m, n, next.y, next.x)) {
                grid[next.y][next.x] = '0';
                dfs(grid, next);
            }
        }
    }

    int numIslands(vector<vector<char> > &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size(), n = grid[0].size(), result = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    dfs(grid, Position(i, j));
                    result ++;
                }
            }
        }
        return result;
    }
};
