/*=============================================================================
#     FileName: 201-BitwiseANDOfNumbersRange.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-06-18 21:28:45
#      History:
=============================================================================*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int power(int x, int y) {
        int result = 1;
        for (int i = 0; i < y; i ++) {
            result *= x;
        }
        return result;
    }

    //146ms
    int rangeBitwiseAnd(int m, int n) {
        int result = 0, len = 32;
        vector<vector<int> > flag(len, vector<int>(2, 0));
        for (int i = 0; i < len; i ++) {
            flag[i][0] = (m & (1 << i)) >> i;
            flag[i][1] = (n & (1 << i)) >> i;
        }
        for (int i = len - 1; i >= 0; i --) {
            if (flag[i][0] && flag[i][1]) {
                result += power(2, i);
            } else if (!flag[i][0] && !flag[i][1]) {
                continue;
            } else {
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.rangeBitwiseAnd(5, 7) << endl;
}
