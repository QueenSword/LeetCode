/*=============================================================================
#     FileName: 162-FindPeakElement.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 11:50:25
#      Version: 0.0.1
#   LastChange: 2015-05-12 11:53:19
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <leetcode.h>

class Solution {
public:

    //8ms
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return 0;
        }
        for (int i = 0; i < len; i ++) {
            if (i == 0) {
                if (nums[i] > nums[i + 1]) {
                    return i;
                }
            } else if (i == len - 1) {
                if (nums[i] > nums[i - 1]) {
                    return i;
                }
            } else {
                if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                    return i;
                }
            }
        }
        return 0;
    }

};
