/*=============================================================================
#     FileName: 43-MultiplyStrings.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-08 13:15:37
#      Version: 0.0.1
#   LastChange: 2015-04-08 13:15:37
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>

using namespace std;

class Solution {
public:
    char add(char a, char b, char &c) {
        int sum = (a - '0') + (b - '0') + (c - '0');
        c = sum > 9 ? '1' : '0';
        sum %= 10;
        return (sum + '0');
    }
    string add(string num1, string num2) {
        string result = "";
        if (num1.length() < num2.length()) {
            num1.swap(num2);
        }
        int deta = num1.length() - num2.length();
        for (int i = 0;i < deta; i ++) {
            num2 = '0' + num2;
        }
        char c = '0';
        for (int i = 0; i < (int)(num1.length()); i ++) {
            result = add(num1[num1.length() - 1 -i], num2[num2.length() - 1 -i], c) + result; 
        }
        if (c != '0') {
            result = c + result;
        }
        return result;
    }

    char multiply(char a, char b, char &c) {
        int sum = (a - '0') * (b - '0') + (c - '0');
        c = (sum / 10 + '0');
        sum %= 10;

        return (sum + '0');
    }
    
    string multiply(string str, char b) {
        string result = "";
        char c = '0';
        for (int i = 0; i < str.length(); i ++) {
            result = multiply(str[str.length() - 1 - i], b, c) + result;
        }
        if (c != '0') {
            result = c + result;
        }
        return result;
    }
    
    //121ms
    string multiply(string num1, string num2) {
        if (num1 == "" || num2 == "") {
            return "";
        }
        string result = "";
        for (int i = 0; i < num2.length(); i ++) {
            string tmp = multiply(num1, num2[num2.length() - 1 - i]);
            for (int j = 0; j < i; j ++) {
                tmp += '0';
            }
            result = add(result, tmp);
        }
        int index = 0;
        while (index < result.size() && result[index] == '0') {
            index ++;
        }
        return index == result.size() ? "0" : result.substr(index, result.length() - index);
    }
};

int main() {
    Solution solution;
    cout << solution.multiply("33", "11") << endl;

    return 0;
}

