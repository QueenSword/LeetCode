/*=============================================================================
#     FileName: 4-MedianofTwoSortedArrays.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-03-21 17:09:59
#      Version: 0.0.1
#   LastChange: 2015-03-21 18:42:11
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    //50ms
    double findKthSortedArrays(int A[], int m, int B[], int n, int k) { // k [1, m + n]
        if (m == 0) {
            return B[k - 1];
        }
        if (n == 0) {
            return A[k -1];
        }
        if (k == 1) {
            return min(A[0], B[0]);
        }
        if (k == m + n) {
            return max(A[m - 1], B[n - 1]);
        }
        
        int numA = min(m, k / 2), numB = min(n, k - numA);
        if (A[numA - 1] == B[numB - 1]) {
            return A[numA - 1];
        } else if (A[numA - 1] > B[numB - 1]) {
            return findKthSortedArrays(A, numA, B + numB, n - numB, k - numB);
        } else {
            return findKthSortedArrays(A + numA, m - numA, B, n, k - numA);
        }
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) % 2) {
            return findKthSortedArrays(A, m, B, n, (m + n) / 2 + 1);
        } else {
            return (findKthSortedArrays(A, m, B, n, (m + n + 1) / 2 + 1) + findKthSortedArrays(A, m, B, n, (m + n - 1) / 2 + 1)) / 2;
        }
    }

};

int main() {
    int A[] = {};
    int B[] = {1};
    Solution solution;
    printf("median is :%f\n", solution.findMedianSortedArrays(A, sizeof(A) / sizeof(int), B, sizeof(B) / sizeof(int)));
    return 0;
}
