/*=============================================================================
#     FileName: 169-MajorityElement.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 14:29:20
#      Version: 0.0.1
#   LastChange: 2015-05-12 14:29:20
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    //52ms
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }
        int count = 1, num = nums[0]; 
        for (int i = 1; i < len; i ++) {
            if (nums[i] == num) {
                count ++;
            } else {
                count --;
            }
            if (count < 0) {
                count = 0;
                num = nums[i];
            }
        }
        return num;

    }

};
