/*=============================================================================
#     FileName: 119-PascalsTriangleII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-08 19:44:04
#      Version: 0.0.1
#   LastChange: 2015-05-08 19:50:20
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    //4ms 
    vector<int> getRow(int numRows) {
        vector<vector<int> > result;
        vector<int> ret;
        numRows ++;
        if (numRows < 1) {
            return ret;
        }
        for (int i = 0; i < numRows; i ++) {
            ret.clear();
            for (int j = 0; j < i + 1; j ++) {
                if (j == 0 || j == i) {
                    ret.push_back(1);
                } else {
                    ret.push_back(result[i - 1][j - 1] + result[i - 1][j]);
                }
            }
            result.push_back(ret);
        }
        return result[numRows - 1];
    }

};
