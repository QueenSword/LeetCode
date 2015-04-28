/*=============================================================================
#     FileName: 62-UniquePaths.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-28 22:22:34
#      Version: 0.0.1
#   LastChange: 2015-04-28 22:38:36
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <math.h>

class Solution {

public:
    //4ms 
    int calc(int n, int m) {
        if (m == 0 || m == n) {
            return 1;
        }
        if (m == 1 || m == n - 1) {
            return n;
        }
        if (m > n / 2) {
            return calc(n, n - m);
        }
        
        double ret = 0;
        for (int i = n - m + 1; i <= n; i ++) {
            ret += log(i);
        }
        for (int i = 1; i <= m; i ++) {
            ret -= log(i);
        }
        ret = exp(ret);
        return (int)(ret + 0.5);
    }

    int uniquePaths(int m, int n) {
        return calc(m + n - 2, m - 1);
    }
};

int main() {
    Solution solution;
    printf("%d\n", solution.uniquePaths(3, 2));
}
