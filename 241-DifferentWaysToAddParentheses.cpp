/*=============================================================================
#     FileName: 241-DifferentWaysToAddParentheses.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-07-30 12:15:12
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        bool isOp(char c) {
            return c == '+' || c == '-' || c == '*' || c == '/';
        }
        int operate(char op, int num1, int num2) {
            switch (op) {
                case '+':
                    return num1 + num2;
                case '-':
                    return num1 - num2;
                case '*':
                    return num1 * num2;
                case '/':
                    return num1 / num2;
            }
            return 0;
        }
        vector<int> diffWaysToCompute(string input) {
            vector<int> result;
            int len = input.length();
            for (int i = 0; i < len; i ++) {
                char c = input[i];
                if (isOp(c)) {
                    vector<int> res1 = diffWaysToCompute(input.substr(0, i)), res2 = diffWaysToCompute(input.substr(i + 1, len - i - 1));
                    for (int j = 0; j < (int)res1.size(); j ++) {
                        for (int k = 0; k < (int)res2.size(); k ++) {
                            result.push_back(operate(c, res1[j], res2[k]));
                        }
                    }
                }
            }
            if (result.empty()) {
                result.push_back(atoi(input.c_str()));
            }
            return result;
        }
};

int main() {
    Solution solution;
    vector<int> result = solution.diffWaysToCompute("2*3-4*5");
    for (int i = 0; i < (int)result.size(); i ++) {
        cout << result[i] << " ";
    }
    cout << endl;
}
