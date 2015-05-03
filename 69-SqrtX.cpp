/*=============================================================================
#     FileName: 69-SqrtX.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-29 22:10:37
#      Version: 0.0.1
#   LastChange: 2015-04-29 22:10:37
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <stdlib.h>

class Solution {
public:
    int find_binary(int x, int low, int high) {
        if (low + 1 == high) {
            return x / high >= high ? high : low;
        }
        int mid = (low + high) >> 1;
        if (mid == x / mid) {
            if (x % mid == 0) {
                return mid;
            } else {
                return find_binary(x, mid, high);
            }
        } else if (mid < x / mid) {
            return find_binary(x, mid, high);
        } else {
            return find_binary(x, low, mid);
        }
    }
    
    //15ms
    int mySqrt(int x) {
        if (x <= 0) {
            return 0;
        } else if (x == 1) {
            return 1;
        }
        return find_binary(x, 1, x);
    }
};

int main() {
    int n;
    Solution solution;
    while (scanf("%d", &n)) {
        printf("%d\n", solution.mySqrt(n));
    }

    return 0;
}
