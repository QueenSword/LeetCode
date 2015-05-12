/*=============================================================================
#     FileName: 204-CountPrimes.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 21:04:40
#      Version: 0.0.1
#   LastChange: 2015-05-12 21:25:07
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <leetcode.h>

class Solution {
public:

    //743ms
    int countPrimes(int n) {
        int count = 0;
        vector<bool> is_prime(n, true);
        n --;
        for (int i = 2; i <= n / i; i ++) {
            for (int j = 2; j <= n / i; j ++) {
                is_prime[i * j] = false;
            }
        }
        for (int i = 2; i <= n; i ++) {
            if (is_prime[i]) {
                count ++;
            }
        }
        return count;
    }
};
