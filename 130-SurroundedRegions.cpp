/*=============================================================================
#     FileName: 130-SurroundedRegions.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-09 17:53:39
#      Version: 0.0.1
#   LastChange: 2015-05-09 17:53:39
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <queue>

using namespace std;

struct Position {
    int x;
    int y;
    Position(int _y, int _x) : x(_x), y(_y) {}
    Position *add(int _x, int _y) {
        return new Position(x + _x, y + _y);
    }
};

class Solution {
public:

    //21ms
    void solve(vector<vector<char> >& board) {
        if (board.size() < 3) {
            return ;
        }
        int m = board.size(), n = board[0].size();
        if (n < 3) {
            return ;
        }
        queue<Position *> pos_queue;
        for (int i = 0; i < m; i ++) {
            if (board[i][0] == 'O') {
                board[i][0] = 'L';
                pos_queue.push(new Position(i, 0));
            }
            if (board[i][n - 1] == 'O') {
                board[i][n - 1] = 'L';
                pos_queue.push(new Position(i, n - 1));
            }
        }
        for (int j = 1; j < n - 1; j ++) {
            if (board[0][j] == 'O') {
                board[0][j] = 'L';
                pos_queue.push(new Position(0, j));
            }
            if (board[m - 1][j] == 'O') {
                board[m - 1][j] = 'L';
                pos_queue.push(new Position(m - 1, j));
            }
        }
        int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!pos_queue.empty()) {
            Position *pos = pos_queue.front();
            pos_queue.pop();
            for (int i = 0; i < 4; i ++) {
                int x = pos->x + direction[i][0];
                int y = pos->y + direction[i][1];
                if (x < 0 || x >= n || y < 0 || y >= m || board[y][x] != 'O') {
                    continue;
                }
                board[y][x] = 'L';
                pos_queue.push(new Position(y, x));
            }
        }
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'L') {
                    board[i][j] = 'O';
                }
            }
        }
        
        
    }
};

int main() {
    srand(100);
    string strs[] = {"OXOOOX","OOXXXO","XXXXXO","OOOOXX","XXOOXO","OOXXXX"};
    vector<vector<char> > board;
    for (int i = 0; i < 6; i ++) {
        vector<char> b;
        for (int j = 0; j < strs[i].length(); j ++) {
            //char c = rand() % 2 ? 'O' : 'X';

            b.push_back(strs[i][j]);
        }
        board.push_back(b);
    }
    for (int i = 0; i < board.size(); i ++) {
        for (int j = 0; j < board[0].size(); j ++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    Solution solution;
    solution.solve(board);
    for (int i = 0; i < board.size(); i ++) {
        for (int j = 0; j < board[0].size(); j ++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
