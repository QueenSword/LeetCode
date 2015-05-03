/*=============================================================================
#     FileName: 80-RemoveDuplicatesFromSortedArrayII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-30 12:13:58
#      Version: 0.0.1
#   LastChange: 2015-04-30 12:13:58
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>

class Solution {
public:

    //22ms
    int removeDuplicates(int A[], int n) {
        if (n < 3) {
            return n;
        }
        int prev_num = A[0], repeat_num = 1, len = 1;
        for (int i = 1; i < n; i ++) {
            if (A[i] == prev_num) {
                if (repeat_num < 2) {
                    repeat_num ++;
                    A[len ++] = A[i];
                }
            } else {
                prev_num = A[i];
                repeat_num = 1;
                A[len ++] = A[i];
            }
        }
        return len;
    }
};
