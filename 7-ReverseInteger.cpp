/*=============================================================================
#     FileName: 7-ReverseInteger.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-04 23:03:05
#      Version: 0.0.1
#   LastChange: 2015-04-04 23:03:05
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    //24ms
    int reverse(int x) {
        if (x == 0) {
            return x;
        }
        if (x == INT_MIN) {
            return 0;
        }
        bool flag = x < 0 ? true : false;
        x *= flag ? (-1) : 1;
        string s = "";
        while (x > 0) {
            s += (char)(x % 10 + '0');
            x /= 10;
        }
        int result = 0, count = 0;
        while (s[count] == '0') {
            count ++;
        }
        s = s.substr(count, s.length() - count);
        cout << s << endl;
        for (int i = 0; i < s.length(); i ++) {
            int num = (int)(s[i] - '0');
            if (result > INT_MAX / 10 || (flag && result*10 - 1> INT_MAX -  num) || (!flag && result * 10 > INT_MAX - num)) {
                return 0;
            } else {
                result = result*10 + num;
            }
        }
        return result * (flag ? -1 : 1);
    }
};

int main() {
    Solution solution;
    cout << solution.reverse(-901000) << endl;
}
