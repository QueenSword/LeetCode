/*=============================================================================
#     FileName: 29-DivideTwoIntegers.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-07 10:12:16
#      Version: 0.0.1
#   LastChange: 2015-04-07 10:12:16
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <limits.h>
#include <math.h>

using namespace std;


class Solution {
public:
    unsigned int divideOnce(unsigned int &dividend, unsigned int divisor) {
        if (dividend < divisor) {
            dividend = 0;
            return 0;
        }
        unsigned int result = 1;
        while (divisor < dividend) {
            result  <<= 1;
            divisor <<= 1;
        }
        if (divisor != dividend) {
            result >>= 1;
            divisor >>= 1;
        }
        dividend -= divisor;
        return result;
    }
    //15ms
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return INT_MAX; 
        }
        if (dividend == 0) {
            return 0;
        }
        bool flag = ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) ? true : false;
        unsigned int result = 0, unDividend = dividend > 0 ? dividend : -dividend, unDivisor = divisor > 0 ? divisor : -divisor;

        while (unDividend != 0) {
            result += divideOnce(unDividend, unDivisor);
        }
        if (flag) {
            return result > INT_MAX ? INT_MAX : result;
        } else {
            return (int)result - 1 > INT_MAX ? INT_MIN : (int)result * (-1);
        }
    }
};

int main() {
    Solution solution;
    cout << solution.divide(1004958205, -2137325331) << endl;
    return 0;
}
