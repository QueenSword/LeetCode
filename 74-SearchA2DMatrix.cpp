/*=============================================================================
#     FileName: 74-SearchA2DMatrix.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-30 07:19:36
#      Version: 0.0.1
#   LastChange: 2015-04-30 07:19:36
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    //19ms
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size(), i = m - 1, j = 0;
        while (true) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] < target && j < n - 1) {
                j ++;
            } else if (matrix[i][j] > target && i > 0) {
                i --;
            } else {
                return false;
            }
        }
    }
};
