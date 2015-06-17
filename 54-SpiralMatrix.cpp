/*=============================================================================
#     FileName: 44-SpiralMatrix.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-06-13 10:50:19
#      Version: 0.0.1
#   LastChange: 2015-06-13 10:50:19
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    void goRight(vector<vector<int> > &matrix, int y, int x, vector<int> &result) {
         int m = matrix.size(), n = matrix[0].size();
         if (result.size() == m * n) {
            return ;
         }
         while (x < n && matrix[y][x] != INT_MIN) {
            result.push_back(matrix[y][x]);
            matrix[y][x ++] = INT_MIN;
         }
         goDown(matrix, y + 1, x - 1, result);
    }
    
    void goDown(vector<vector<int> > &matrix, int y, int x, vector<int> &result) {
         int m = matrix.size(), n = matrix[0].size();
         if (result.size() == m * n) {
            return ;
         }
         while (y < m && matrix[y][x] != INT_MIN) {
            result.push_back(matrix[y][x]);
            matrix[y ++][x] = INT_MIN;
         }
         goLeft(matrix, y - 1, x - 1, result);
    }

    void goLeft(vector<vector<int> > &matrix, int y, int x, vector<int> &result) {
         int m = matrix.size(), n = matrix[0].size();
         if (result.size() == m * n) {
            return ;
         }
         while (x >= 0 && matrix[y][x] != INT_MIN) {
            result.push_back(matrix[y][x]);
            matrix[y][x --] = INT_MIN;
         }
         goUp(matrix, y - 1, x + 1, result);
    }

    void goUp(vector<vector<int> > &matrix, int y, int x, vector<int> &result) {
         int m = matrix.size(), n = matrix[0].size();
         if (result.size() == m * n) {
            return ;
         }
         while (y >= 0 && matrix[y][x] != INT_MIN) {
            result.push_back(matrix[y][x]);
            matrix[y --][x] = INT_MIN;
         }
         goRight(matrix, y + 1, x + 1, result);
    }
    //0ms
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> result; 
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return result;
        }
        goRight(matrix, 0, 0, result);

        return result;
    }
};

int main() {
    vector<int> vec[4];
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 4; j ++) {
            vec[i].push_back(i * 4 + j);
        }
    }
    vector<vector<int> > matrix;
    for (int i = 0; i < 4; i ++) {
        matrix.push_back(vec[i]);
    }
    Solution solution;
    solution.spiralOrder(matrix);
}
