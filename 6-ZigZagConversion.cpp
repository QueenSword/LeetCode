/*=============================================================================
#     FileName: 6-ZigZagConversion.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-03-21 19:16:18
#      Version: 0.0.1
#   LastChange: 2015-03-21 19:20:32
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        int len = s.length();
        if (len <= 1 || nRows <= 1) {
            return s;
        }
        string result = "";
        for (int i = 0; i < nRows; i ++) {
            bool odd = true;
            int j = i;
            while (j < len) {
                result += s[j];
                if (i == 0 || i == nRows - 1) {
                    j += 2 * nRows - 2;
                } else {
                    j += odd ? (2 * nRows - 2 - 2 * i) : 2 * i;
                    odd = !odd;
                }
            }
        }
        return result;
    }
};


int main() {

    return 0;
}

