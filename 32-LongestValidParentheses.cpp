/*=============================================================================
#     FileName: 32-LongestValidParentheses.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-07 14:22:34
#      Version: 0.0.1
#   LastChange: 2015-04-07 14:22:34
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    //Memory Limit Exceeded
    int longestValidParentheses1(string s) {
        if (s == "") {
            return 0;
        }
        int len = s.length(), maxLen = 0;
        vector<vector<int> > dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; i ++) {
            for (int j = i; j < len; j ++) {
                if (i == j) {
                    dp[i][j] = ((s[i] == '(') ? 1 : -1);
                } else {
                    dp[i][j] = dp[i][j - 1] + ((s[j] == '(') ? 1 : -1);
                }
            }
        }
        for (int i = 0; i < len - 1; i ++) {
            for (int j = i + 1; j < len; j ++) {
                if (dp[i][j] == 0) {
                    maxLen = max(j - i + 1, maxLen);
                }
            }
        }
        return maxLen;
    }
    //17ms
    int longestValidParentheses(string s) {
        if (s == "") {
            return 0;
        }
        int len = s.length();
        stack<int> cStack;
        vector<bool> hasMatch(len, false);
        for (int i = 0; i < len; i ++) {
            if (s[i] == '(') {
                cStack.push(i);
            } else if (s[i] == ')' && !cStack.empty()) {
                hasMatch[i] = true;
                hasMatch[cStack.top()] = true;
                cStack.pop();
            }
        }
        int maxLen = 0, curLen = 0;
        for (int i = 0; i < len; i ++) {
            if (hasMatch[i]) {
                curLen ++;
                maxLen = max(maxLen, curLen);
            } else {
                curLen = 0;
            }
        }
        return maxLen;
    }
};

int main() {
    Solution solution;
    cout << solution.longestValidParentheses("))(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())") << endl;
    return 0;
}
