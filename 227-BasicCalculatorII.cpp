/*=============================================================================
#     FileName: 227-BasicCalculatorII.cpp
#         Desc: AC 84ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-06-25 16:43:32
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    
    void getNext(string &s, int &pos, string &cache) {
        int len = s.length();
        cache = "";
        while (pos < len && s[pos] >= '0' && s[pos] <= '9') {
            cache += s[pos ++];
        }
    }

    int calculate(string s) {
        s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());

        stringstream ss;
        stack<char> optStack;
        stack<long long int> numStack;
        
        string cache;
        int pos = 0, len = s.length();
        while (pos < len) {
            char c = s[pos];
            if (c == '*' || c == '/') {
                pos ++;
                getNext(s, pos, cache);
                ss.clear();
                long long int num1 = numStack.top(), num2;
                numStack.pop();
                ss << cache;
                ss >> num2;
                numStack.push(c == '*' ? num1 * num2 : num1 / num2);
            } else if (c == '+' || c == '-') {
                pos ++;
                getNext(s, pos, cache);
                ss.clear();
                long long int num;
                ss << cache;
                ss >> num;
                optStack.push(c);
                numStack.push(num);
            } else {
                getNext(s, pos, cache);
                long long int num;
                ss << cache;
                ss >> num;
                numStack.push(num);
            }
        }
        stack<char> optStack1;
        stack<long long int> numStack1;
        while (!optStack.empty()) {
            optStack1.push(optStack.top());
            optStack.pop();
        }
        while (!numStack.empty()) {
            numStack1.push(numStack.top());
            numStack.pop();
        }
        while (!optStack1.empty()) {
            char opt = optStack1.top();
            optStack1.pop();
            int num1 = numStack1.top();
            numStack1.pop();
            int num2 = numStack1.top();
            numStack1.pop();
            numStack1.push(opt == '+' ? num1 + num2 : num1 - num2);
        }
        return numStack1.top();
    }
};

int main() {
    Solution solution;
    cout << solution.calculate("3+2*2") << endl;
    cout << solution.calculate(" 3/2 ") << endl;
    cout << solution.calculate(" 3+5 / 2 ") << endl;

    return 0;
}
