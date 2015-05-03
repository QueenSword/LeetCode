/*=============================================================================
#     FileName: 88-MergeSortedArray.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-30 13:59:20
#      Version: 0.0.1
#   LastChange: 2015-04-30 13:59:20
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    //8ms
    void merge(int A[], int m, int B[], int n) {
        for (int i = m - 1; i >= 0; i --) {
            A[i + n] = A[i];
        }
        int a = n, b = 0, c = 0;
        while (a < m + n && b < n) {
            if (A[a] <= B[b]) {
                A[c ++] = A[a ++];
            } else {
                A[c ++] = B[b ++];
            }
        }
        if (b < n) {
            while (b < n) {
                A[c ++] = B[b ++];
            }
        }
        return ;
    }

};
