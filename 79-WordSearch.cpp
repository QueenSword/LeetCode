/*=============================================================================
#     FileName: 79-WordSearch.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-30 11:57:50
#      Version: 0.0.1
#   LastChange: 2015-04-30 12:13:35
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    bool result;
public:
    void dfs(vector<vector<char> > &board, string word, int i, int j) {
        if (word == "") {
            result = true;
            return ;
        }
        int m = board.size(), n = board[0].size();
        if (i > 0 && board[i - 1][j] == word[0]) {
            board[i - 1][j] = '$';
            dfs(board, word.substr(1, word.length() - 1), i - 1, j);
            if (result) {
                return ;
            }
            board[i - 1][j] = word[0];
        }
        if (i < m - 1 && board[i + 1][j] == word[0]) {
            board[i + 1][j] = '$';
            dfs(board, word.substr(1, word.length() - 1), i + 1, j);
            if (result) {
                return ;
            }
            board[i + 1][j] = word[0];
        }
        if (j > 0 && board[i][j - 1] == word[0]) {
            board[i][j - 1] = '$';
            dfs(board, word.substr(1, word.length() - 1), i, j - 1);
            if (result) {
                return ;
            }
            board[i][j - 1] = word[0];
        }
        if (j < n - 1 && board[i][j + 1] == word[0]) {
            board[i][j + 1] = '$';
            dfs(board, word.substr(1, word.length() - 1), i, j + 1);
            if (result) {
                return ;
            }
            board[i][j + 1] = word[0];
        }
    }

    //45ms
    bool exist(vector<vector<char> > &board, string word) {
        if (word == "") {
            return true;
        }
        if (board.empty() || board[0].empty()) {
            return false;
        }
        
        int m = board.size(), n = board[0].size();
        result = false;

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '$';
                    dfs(board, word.substr(1, word.length() - 1), i, j);
                    if (result) {
                        return true;
                    }
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }

};
