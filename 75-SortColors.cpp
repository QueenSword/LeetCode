/*=============================================================================
#     FileName: 75-SortColors.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-30 07:24:53
#      Version: 0.0.1
#   LastChange: 2015-04-30 07:24:53
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    //10ms
    void sortColors(int A[], int n) {
        if (n <= 1) {
            return ;
        }
        int start = -1, end = n, i = 0;
        while (i < n) {
            if (A[i] == 0) {
                if (i > start) {
                    swap(A[i], A[++ start]);
                } else {
                    i ++;
                }
            } else if (A[i] == 2) {
                if (i < end) {
                    swap(A[i], A[-- end]);
                } else {
                    i ++;
                }
            } else {
                i ++;
            }
        }
        return ;
    }

};
