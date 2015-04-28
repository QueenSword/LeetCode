/*=============================================================================
#     FileName: 53-MaximumSubarray.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-10 22:51:21
#      Version: 0.0.1
#   LastChange: 2015-04-10 22:51:21
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>

using namespace std;

class Solution {
public:
    //20ms
    int maxSubArray(int A[], int n) {
        if (n < 1) {
            return 0;
        } 
        if (n == 1) {
            return A[0];
        }
        int curSum = A[0], maxSum = curSum;
        for (int i = 1; i < n; i ++) {
            if (curSum < 0) {
                curSum = 0;
            }
            curSum += A[i];
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution solution;
    cout << solution.maxSubArray(nums, sizeof(nums) / sizeof(int)) << endl;
    return 0;
}
