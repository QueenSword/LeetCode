/*=============================================================================
#     FileName: 73-SetMatrixZeroes.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-22 19:10:18
#      Version: 0.0.1
#   LastChange: 2015-04-22 19:10:18
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    //82ms
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return ;
        }
        int m = matrix.size(), n = matrix[0].size();
        bool zeroRow = false, zeroCol = false;
        for (int i = 0; i < m; i ++) {
            if (matrix[i][0] == 0) {
                zeroCol = true;
                break;
            }
        }
        for (int j = 0; j < n; j ++) {
            if (matrix[0][j] == 0) {
                zeroRow = true;
                break;
            }
        }
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i ++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j ++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 1; j < n; j ++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i ++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (zeroRow) {
            for (int j = 0; j < n; j ++) {
                matrix[0][j] = 0;
            }
        }
        if (zeroCol) {
            for (int i = 0; i < m; i ++) {
                matrix[i][0] = 0;
            }
        }
        return ;
    }
};


int main() {
    
    return 0;
}
