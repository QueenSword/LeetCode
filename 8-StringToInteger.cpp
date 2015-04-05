/*=============================================================================
#     FileName: 8-StringToInteger.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-04 23:49:27
#      Version: 0.0.1
#   LastChange: 2015-04-04 23:49:27
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    //16ms
    int atoi(string str) {
        if (str == "") {
            return 0;
        }
        int count = 0, result = 0;
        bool flag;
        while (count < str.length() && str[count] == ' ' /*!(str[count] >= '0' && str[count] <= '9') && str[count] != '+' && str[count] != '-'*/) {
            count ++;
        }
        if (count >= str.length()) {
            return 0;
        }
        str = str.substr(count, str.length() - count);
        if (str[0] == '-') {
            flag = true;
        } else if (str[0] == '+') {
            flag = false;
        } else if (str[0] >= '0' && str[0] <= '9'){
            flag = false;
            result += (int)(str[0] - '0');
        } else {
            return 0;
        }
        for (int i = 1; i < str.length(); i ++) {
            if (str[i] >= '0' && str[i] <= '9') {
                int num = (int)(str[i] - '0');
                if (result > INT_MAX / 10 || (flag && result * 10 - 1 > INT_MAX - num) || (!flag && result * 10 > INT_MAX - num)) {
                    return flag ? INT_MIN : INT_MAX;
                }
                result = result * 10 + num;
            } else {
                return result * (flag ? (-1) : 1);
            }
        }
        return result * (flag ? (-1) : 1);
    }
};

int main() {
    Solution solution;
    cout << solution.atoi("     -11919730356x ") << endl;

}
