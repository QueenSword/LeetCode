/*=============================================================================
#     FileName: 136-SingleNumber.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-10 08:15:46
#      Version: 0.0.1
#   LastChange: 2015-05-10 08:18:50
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    //22ms
    int singleNumber(vector<int>& nums) {
        int result = nums[0], len = nums.size();
        for (int i = 1; i < len; i ++) {
            result ^= nums[i];
        }
        return result;
    }
};
