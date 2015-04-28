/*=============================================================================
#     FileName: 59-SpiralMatrixII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-11 19:07:27
#      Version: 0.0.1
#   LastChange: 2015-04-11 19:07:27
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:

    void go_right(int i, int j, int n, int cur_num, vector<vector<int> > &result) {
        while (1) {
            if (cur_num > n * n) {
                return ;
            }
            if (j >= n || result[i][j] != -1) {
                break;
            } else {
                //printf("%d %d\n", i, j);
                result[i][j ++] = cur_num ++;
            }
        }        
        go_down(i + 1, j - 1, n, cur_num, result);
    }
    
    void go_down(int i, int j, int n, int cur_num, vector<vector<int> > &result) {
        while (1) {
            if (cur_num > n * n) {
                return ;
            }
            if (i >= n || result[i][j] != -1) {
                break;
            } else {
                //printf("%d %d\n", i, j);
                result[i ++][j] = cur_num ++;
            }
        }        
        go_left(i - 1, j - 1, n, cur_num, result);
    }
    
    void go_left(int i, int j, int n, int cur_num, vector<vector<int> > &result) {
        while (1) {
            if (cur_num > n * n) {
                return ;
            }
            if (j < 0 || result[i][j] != -1) {
                break;
            } else {
                printf("%d %d\n", i, j);
                result[i][j --] = cur_num ++;
            }
        }
        go_up(i - 1, j + 1, n, cur_num, result);
    }
    
    void go_up(int i, int j, int n, int cur_num, vector<vector<int> > &result) {
        while (1) {
            if (cur_num > n * n) {
                return ;
            }
            if (i < 0 || result[i][j] != -1) {
                break;
            } else {
                //printf("%d %d\n", i, j);
                result[i --][j] = cur_num ++;
            }
        }        
        go_right(i + 1, j + 1, n, cur_num, result);
    }
    
    //5ms 
    vector<vector<int> > generateMatrix(int n) {
        if (n == 0) {
            vector<vector<int> > ret;
            return ret;
        }
        vector<vector<int> > vec(n, vector<int>(n, -1));
        go_right(0, 0, n, 1, vec);    
        return vec;
    }
};

int main() {
    Solution solution;
    vector<vector<int> > vec = solution.generateMatrix(3);
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            printf("%d ", vec[i][j]);
        }
        printf("\n");
    }
    return 0;
}
