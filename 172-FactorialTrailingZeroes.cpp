/*=============================================================================
#     FileName: 172-FactorialTrailingZeroes.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 14:36:45
#      Version: 0.0.1
#   LastChange: 2015-05-12 16:24:56
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    //7ms
    int trailingZeroes(int n) {
        int ret = 0;
        while (n / 5 != 0) {
            n /= 5;
            ret += n;
        }
        return ret;
    }

};

