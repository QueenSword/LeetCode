/*=============================================================================
#     FileName: 154-FindMinimumInRotatedSortedArrayII.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-06-17 20:54:18
#      Version: 0.0.1
#   LastChange: 2015-06-17 21:00:48
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //8ms
    int findMinBinary(vector<int> &nums, int low, int high) {
        if (high - low <= 1) {
            return min(nums[low], nums[high]);
        }
        int mid = (low + high) >> 1;
        if (nums[mid] > nums[high]) {
            return findMinBinary(nums, mid + 1, high);
        }
        if (nums[low] > nums[mid]) {
            return findMinBinary(nums, low + 1, mid);
        }
        return min(findMinBinary(nums, low, mid), findMinBinary(nums, mid, high));
    }

    int findMin(vector<int>& nums) {
        return findMinBinary(nums, 0, nums.size() - 1);
    }
};
