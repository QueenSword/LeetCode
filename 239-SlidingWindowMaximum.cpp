/*=============================================================================
#     FileName: 239-SlidingWindowMaximum.cpp
#         Desc: AC
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-07-31 07:50:17
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int len = nums.size();
            vector<int> result, rightMax(k, 0);
            if (len == 0) {
                return result;
            }
            for (int i = 0; i < len - k + 1; i ++) {
                if (i == 0) {
                    for (int j = k - 1; j > -1; j --) {
                        int num = nums[j];
                        rightMax[j] = j == k - 1 ? num : max(rightMax[j + 1], num);
                    }
                } else {
                    int num = nums[k + i - 1];
                    for (int j = 0; j < k; j ++) {
                        rightMax[j] = j == k - 1 ? num : max(rightMax[j + 1], num);
                    }
                }
                result.push_back(rightMax[0]);
            }
            return result;
        }
};

