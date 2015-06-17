/*=============================================================================
#     FileName: 37-SudokuSolver.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-06-13 10:18:35
#      Version: 0.0.1
#   LastChange: 2015-06-13 10:48:10
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //84ms
    bool isValidSudoku(vector<vector<char> > &board, int x, int y) {
        int row, col;
        
        // Same value in the same column?
        for (row = 0; row < 9; ++row) {
            if ((x != row) && (board[row][y] == board[x][y])) {
                return false;
            }
        }
        
        // Same value in the same row?
        for (col = 0; col < 9; ++col) {
            if ((y != col) && (board[x][col] == board[x][y])) {
                return false;
            }
        }
        
        // Same value in the 3 * 3 block it belong to?
        for (row = (x / 3) * 3; row < (x / 3 + 1) * 3; ++row) {
            for (col = (y / 3) * 3; col < (y / 3 + 1) * 3; ++col) {
                if ((x != row) && (y != col) && (board[row][col] == board[x][y])) {
                    return false;
                }
            }
        }
        
        return true;
    } 
    
    bool internalSolveSudoku(vector<vector<char> >& board) {
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.') {
                    for (int k = 0; k < 9; k ++) {
                        board[i][j] = char('1' + k);
                        if (isValidSudoku(board, i, j)) {
                            if (internalSolveSudoku(board)) {
                                return true;
                            }
                        }
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char> >& board) {
        internalSolveSudoku(board); 
    }

};
