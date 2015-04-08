/*=============================================================================
#     FileName: 41-FirstMissingPositive.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-08 10:51:59
#      Version: 0.0.1
#   LastChange: 2015-04-08 10:51:59
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>

using namespace std;

class Solution {
public:
    //7ms
    int firstMissingPositive(int A[], int n) {
        if (n < 1) {
            return 1;
        }
        int index = 0;
        while (index < n) {
            if (A[index] <= 0 || A[index] > n || A[index] == index + 1 || A[index] == A[A[index] - 1]) {
                index ++;
            } else {
                swap(A[A[index] - 1], A[index]);
            }
        }
        for (int i = 0; i < n; i ++) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }

};

int main() {
    int A[] = {2, 1};
    Solution solution;
    cout << solution.firstMissingPositive(A, 2) << endl;
    return 0;
}
