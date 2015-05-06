/*=============================================================================
#     FileName: 9-PalindromeNumber.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-05 00:28:10
#      Version: 0.0.1
#   LastChange: 2015-05-06 21:02:51
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>

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
    
    //130ms
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }
        int count = 0, temp = x;
        while (temp > 0) {
            count ++;
            temp /= 10;
        }
        while (count > 1) {
            int a = x % 10, b = x / power(10, count - 1);
            if (a != b) {
                return false;
            }
            x %= power(10, count - 1);
            x /= 10;
            count -= 2;
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.isPalindrome(121) << endl;
    
    return 0;
}
