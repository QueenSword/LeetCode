/*=============================================================================
#     FileName: 137-SingleNumberII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-10 08:20:50
#      Version: 0.0.1
#   LastChange: 2015-05-10 08:26:44
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    //35ms
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int count, result = 0;
        for (int i = 0; i < 32; i ++) {
            count = 0;
            for (int j = 0; j < len; j ++) {
                count += ((nums[j] >> i) & 1);
            }
            result |= ((count % 3) << i);
        }
        return result;
    }
};
