/*=============================================================================
#     FileName: 191-NumberOf1Bits.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-09 17:03:53
#      Version: 0.0.1
#   LastChange: 2015-04-09 17:03:54
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <stdint.h>

using namespace std;

class Solution {
public:

    //10ms
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n > 0) {
            n = n & (n - 1);
            count ++;
        }
        return count;
    }
};

int main() {
    return 0;
}
