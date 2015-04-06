/*=============================================================================
#     FileName: 20-ValidParentheses.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-06 11:42:37
#      Version: 0.0.1
#   LastChange: 2015-04-06 11:42:37
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <stack>

using namespace std;


class Solution {
public:
    bool isMatch(char a, char b) {
        return ((a == '[' && b == ']') || (a == '{' && b == '}') || (a == '(' && b == ')')) ? true : false;
    }

    bool isLeft(char a) {
        return (a == '(' || a == '{' || a == '[') ? true : false;
    }
    
    //2ms
    bool isValid(string s) {
        stack<char> cStack;
        for (int i = 0; i < s.length(); i ++) {
            if (isLeft(s[i])) {
                cStack.push(s[i]);
            } else {
                if (cStack.empty()) {
                    return false;
                } else if (!isMatch(cStack.top(), s[i])) {
                    return false;
                } else {
                    cStack.pop();
                }
            }
        }
        
        return cStack.empty() ? true : false;
    }
};

int main() {
    Solution solution;
    cout << solution.isValid("[]{}([])") << endl;
    return 0;
}
