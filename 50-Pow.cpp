/*=============================================================================
#     FileName: 50-Pow.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-10 20:48:03
#      Version: 0.0.1
#   LastChange: 2015-04-10 20:48:03
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <limits.h>
using namespace std;


class Solution {
public:
    //7ms
    double pow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (x == 0) {
            return 0;
        }
        if (n == 1) {
            return x;
        }
        if (n == INT_MIN) {
            return 1 / (pow(x, INT_MAX) * x);
        }
        if (n < 0) {
            return 1.0/pow(x, -n);
        }
        
        double result = pow(x, n / 2);
        return n % 2 ? result * result * x : result * result;
    }
};

int main() {
    Solution solution;
    cout << solution.pow(3, 3) << endl;
    return 0;
}
