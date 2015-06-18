/*=============================================================================
#     FileName: 209-MinimumSizeSubarraySum.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-06-18 10:10:29
#      Version: 0.0.1
#   LastChange: 2015-06-18 10:27:20
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //4ms
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size(), start = 0, end = 0, minLen = INT_MAX, total = 0;
        while (end < len) {
            total += nums[end];
            if (total >= s) {
                minLen = min(minLen, end - start + 1);
                while (start < end && total >= s) {
                    total -= nums[start ++];
                    if (total >= s) {
                        minLen = min(minLen, end - start + 1);
                    }
                }
            }
            end ++;
        }
        return  minLen == INT_MAX ? 0 : minLen;
    }
};
