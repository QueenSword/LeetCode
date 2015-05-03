/*=============================================================================
#     FileName: 67-AddBinary.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-29 14:36:49
#      Version: 0.0.1
#   LastChange: 2015-04-29 14:47:44
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    char add_char(char a, char b, char &c) {
        int sum = (a - '0') + (b - '0') + (c - '0');
        c = sum > 1 ? '1' : '0';
        sum %= 2;
        return (sum + '0');
    }
    
    //12ms
    string addBinary(string a, string b) {
        if (a.length() < b.length()) {
            a.swap(b);
        }
        while (a.length() != b.length()) {
            b = '0' + b;
        }
        char c = '0';
        string ret = "";
        for (int i = (int)a.length() - 1; i >= 0; i --) {
            ret = add_char(a[i], b[i], c) + ret;
        }
        if (c != '0') {
            ret = c + ret;
        }
        return ret;
    }

};
