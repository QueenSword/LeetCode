/*=============================================================================
#     FileName: 38-CountAndSay.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-08 09:57:10
#      Version: 0.0.1
#   LastChange: 2015-04-08 09:57:10
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>

using namespace std;

class Solution {
public:
    //10ms
    string int2Str(int n) {
        string result = "";
        if (n < 0) {
            return "";
        }
        if (n < 10) {
            result += (char)(n + '0');
            return result;
        }

        while (n > 0) {
            result = (char)(n % 10 + '0') + result;
            n /= 10;
        }
        return result;
    }

    string getNext(string str) {
        string result = "";
        int lastPos = 0, curPos = 0, len = str.length();
        while (curPos < len) {
            if (str[curPos] == str[lastPos]) {
                curPos ++;
            } else {
                result = result + int2Str(curPos - lastPos) + str[lastPos];
                lastPos = curPos;
            }
        }
        result = result + int2Str(curPos - lastPos) + str[lastPos];
        return result; 
    }

    string countAndSay(int n) {
        string str = "1";
        for (int i = 0; i < n -1; i ++) {
            str = getNext(str);
        }
        return str;
    }
};

int main() {
    Solution solution;
    cout << solution.countAndSay(4) << endl;
    return 0;
}
