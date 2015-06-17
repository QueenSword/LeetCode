/*=============================================================================
#     FileName: 166-FractionToRecurringDecimal.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 13:16:47
#      Version: 0.0.1
#   LastChange: 2015-05-31 19:26:50
#      History:
#               0.0.1 | qsword | init
=============================================================================*/


#include <cstdio>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <string>
#include <limits.h>
#include <sstream>


using namespace std;

class Solution {
public:
    //4ms
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) {
            return "";
        }
        if (numerator == 0) {
            return "0";
        }
        
        unsigned long uNumerator, uDenominator;
        if (numerator == INT_MIN) {
            uNumerator = (unsigned)INT_MAX + 1;
        } else {
            uNumerator = numerator >= 0 ? numerator : -numerator;
        }
        if (denominator == INT_MIN) {
            uDenominator = (unsigned)INT_MAX + 1;
        } else {
            uDenominator = denominator >= 0 ? denominator : -denominator;
        }
        bool flag = (numerator > 0 && denominator > 0) || (numerator < 0 && denominator < 0) ? true : false;
        map<int, int> posMap;
        map<int, int>::iterator it;
        stringstream ss;
        string result;
        ss << uNumerator / uDenominator;
        ss >> result;
        uNumerator = uNumerator % uDenominator;
        if (!uNumerator) {
            return flag ? result : '-' + result;
        }
        result += '.';
        posMap.insert(pair<int, int>(uNumerator, result.length()));
        while (true) {
            uNumerator = uNumerator * 10;
            char tmp = char('0' + uNumerator / uDenominator);
            result += tmp;
            uNumerator %= uDenominator;
            if (!uNumerator) {
                return flag ? result : '-' + result;
            }
            it = posMap.find(uNumerator);
            if (it != posMap.end()) {
                string str = result.substr(0, it->second);
                str += '(';
                str += result.substr(it->second, result.length() - it->second);
                str += ')';
                return flag ? str : '-' + str;
            } else {
                posMap.insert(pair<int, int>(uNumerator, result.length()));
            }
        }
    }
};

int main() {
    Solution solution;
    string s = solution.fractionToDecimal(-1, -2147483648);
//    printf("%s\n", s.c_str());
    cout << s << endl;
    return 0;
}
