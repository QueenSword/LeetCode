/*=============================================================================
#     FileName: 231-PowerOfTwo.cpp
#         Desc: AC
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-07-29 19:20:02
#      History:
=============================================================================*/
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        int count = 0;
        while (n) {
            n = n & (n - 1);
            count ++;
        }
        return count == 1 ? true : false;
    }
};

int main() {

}
