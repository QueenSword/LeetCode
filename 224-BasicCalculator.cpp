/*=============================================================================
#     FileName: 224-BasicCalculator.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-06-18 21:12:29
#      History:
=============================================================================*/

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    //48ms
    int calculate(string s) {
        s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
        
        stringstream ss;
        stack<char> optStack;
        stack<int> numStack;

        string cache;
        int pos = 0, len = s.length();
        while (pos < len) {
            char c = s[pos];
            if (c == '(' || c == '+' || c == '-') {
                optStack.push(c);
                pos ++;
            } else if (c == ')') {
                optStack.pop();
                pos ++;
                if (!optStack.empty() && (optStack.top() == '+' || optStack.top() == '-')) {
                    int num2 = numStack.top();
                    numStack.pop();
                    int num1 = numStack.top();
                    numStack.pop();
                    numStack.push(optStack.top() == '+' ? num1 + num2 : num1 - num2);
                    optStack.pop();
                }
            } else {
                int num2 = 0;
                while (pos < len && s[pos] >= '0' && s[pos] <= '9') {
                    num2 = num2 * 10 + (s[pos ++] - '0');
                }
                if (optStack.empty()) {
                    numStack.push(num2);
                } else if (optStack.top() == '+' || optStack.top() == '-') {
                    int num1 = numStack.top();
                    numStack.pop();
                    numStack.push(optStack.top() == '+' ? num1 + num2 : num1 - num2);
                    optStack.pop();
                } else {
                    numStack.push(num2);
                }
            }
        }
        while (!optStack.empty()) {
            int num2 = numStack.top();
            numStack.pop();
            int num1 = numStack.top();
            numStack.pop();
            numStack.push(optStack.top() == '+' ? num1 + num2 : num1 - num2);
            optStack.pop();
        }
        return numStack.top();
    }
};

int main() {
    Solution solution;
    cout << solution.calculate("1+1") << endl;
    return 0;
}
