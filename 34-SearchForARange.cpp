/*=============================================================================
#     FileName: 34-SearchForARange.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-07 15:18:14
#      Version: 0.0.1
#   LastChange: 2015-04-07 15:18:14
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
private:
    int left, right;
public:
    
    void serachByBinary(int A[], int low, int high, int target) {
        if (low > high) {
            return ;
        }
        int mid = (low + high) >> 1;
        if (A[mid] < target) {
            serachByBinary(A, mid + 1, high, target);
            return ;
        } else if (A[mid] > target) {
            serachByBinary(A, low, mid - 1, target);
            return ;
        }
        int l = mid, r = mid;
        while (l >= low && A[l] == target) {
            l --;
        }
        while (r <= high && A[r] == target) {
            r ++;
        }
        left = l + 1;
        right = r - 1;
    }
    //16ms
    vector<int> searchRange(int A[], int n, int target) {
        left = -1, right = -1;
        serachByBinary(A, 0, n - 1, target);
        vector<int> result;
        result.push_back(left);
        result.push_back(right);
        return result;
    }
};

int main() {
    int nums[] = {5, 7, 7, 8, 8, 10};
    vector<int> num;
    for (int i = 0; i < sizeof(nums) / sizeof(int); i ++) {
        num.push_back(nums[i]);
    }
    Solution solution;
    vector<int> result = solution.searchRange(nums, sizeof(nums) / sizeof(int), 8);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
