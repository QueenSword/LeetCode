/*=============================================================================
#     FileName: 238-ProductOfArrayExceptSelf.cpp
#         Desc: AC, 68ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-07-30 10:59:45
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> left(len, 1), right(len, 1), result(len, 0);
        for (int i = 0; i < len; i ++) {
            left[i] = i == 0 ? nums[i] : nums[i] * left[i - 1];
        }
        for (int i = len - 1; i > - 1; i --) {
            right[i] = i == len - 1 ? nums[i] : nums[i] * right[i + 1];
        }
        for (int i = 0; i < len; i ++) {
            if (i == 0) {
                result[i] = right[1];
            } else if (i == len - 1) {
                result[i] = left[len - 2];
            } else {
                result[i] = left[i - 1] * right[i + 1];
            }
        }
        return result;
    }

};

