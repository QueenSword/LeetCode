/*=============================================================================
#     FileName: 33-SearchInRotatedSortedArray.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-07 15:47:50
#      Version: 0.0.1
#   LastChange: 2015-04-07 15:47:50
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
private:
    int result;

public:
    //10ms
    void searchBinary(int A[], int low, int high, int target) {
        if (low > high) {
            return ;
        }
        int mid = (low + high) >> 1;
        if (target == A[mid]) {
            result = mid;
            return ;
        }
        if (target < A[mid]) {
            if (A[mid] < A[low]) {
                searchBinary(A, low, mid - 1, target);
                return ;
            } else {
                searchBinary(A, low, mid - 1, target);
                if (result == -1) {
                    searchBinary(A, mid + 1, high, target);
                }
                return ;
            }
        } else {
            if (A[mid] > A[high]) {
                searchBinary(A, mid + 1, high, target);
                return ;
            } else {
                searchBinary(A, low, mid - 1, target);
                if (result == -1) {
                    searchBinary(A, mid + 1, high, target);
                }
                return ;
            }
        }
    }

    int search(int A[], int n, int target) {
        result = -1;
        searchBinary(A, 0, n - 1, target);
        return result;
    }
};

int main() {
    int A[] = {4, 5, 6, 7, 0, 1, 2};
    Solution solution;
    for (int i = 0; i < 7; i ++) {
        cout << solution.search(A, 7, A[i]) << endl;
    }
    return 0;
}
