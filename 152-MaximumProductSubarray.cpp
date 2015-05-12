/*=============================================================================
#     FileName: 152-MaximumProductSubarray.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 11:01:45
#      Version: 0.0.1
#   LastChange: 2015-05-12 11:24:38
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    //9ms
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }
        int global_max = nums[0], cur_max = nums[0], cur_min = nums[0];
        for (int i = 1; i < len; i ++) {
            int tmp = cur_max;
            tmp = max(cur_min * nums[i], max(cur_max * nums[i], nums[i]));
            cur_min = min(cur_min * nums[i], min(cur_max * nums[i], nums[i]));
            cur_max = tmp;
            global_max = max(global_max, cur_max);
        }

        return global_max;
    }

};

int main() {
    int nums[] = {-4, -3, -2};
    vector<int> vec;
    for (int i = 0; i < sizeof(nums) / sizeof(int); i ++) {
        vec.push_back(nums[i]);
    }
    Solution solution;
    printf("%d\n", solution.maxProduct(vec));
    return 0;
}
