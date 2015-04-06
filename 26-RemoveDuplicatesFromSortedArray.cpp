/*=============================================================================
#     FileName: 26-RemoveDuplicatesFromSortedArray.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-06 23:39:51
#      Version: 0.0.1
#   LastChange: 2015-04-06 23:39:51
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    //40ms
    int removeDuplicates(int A[], int n) {
        if (n < 2) {
            return n;
        }
        int lastPos = 0;
        for (int i = 1; i < n; i ++) {
            if (A[i] == A[lastPos]) {
                A[i] = INT_MAX;
            } else {
                lastPos = i;
            }
        }
        int count = 1;
        for (int i = 1; i < n; i ++) {
            if (A[i] != INT_MAX) {
                A[count ++] = A[i];
            }
        }
        return count;
    }
};

int main() {
    return 0;
}
