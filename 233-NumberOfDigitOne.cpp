/*=============================================================================
#     FileName: 233-NumberOfDigitOne.cpp
#         Desc: AC
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-07-29 19:41:10
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int countDigitOne(int n) {
            int ones = 0;
            for (long m = 1; m <= n; m *= 10) {
                long a = n / m, b = n % m;
                ones += (a + 8) / 10 * m;
                if (a % 10 == 1) {
                    ones += b + 1;
                }
            }
            return ones;
        }

};
