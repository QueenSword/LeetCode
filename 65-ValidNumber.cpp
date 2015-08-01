/*=============================================================================
#     FileName: 65-ValidNumber.cpp
#         Desc: AC, 12ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-01 10:44:03
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        bool isNumber(string s) {
            enum InputType {
                INVALID,
                SPACE,
                SIGN,
                DIGIT,
                DOT,
                EXPONENT,
                NUM_INPUTS
            };
            int transitionTable[][NUM_INPUTS] =
            {
                -1,  0,  3,  1,  2, -1,     // next states for state 0
                -1,  8, -1,  1,  4,  5,     // next states for state 1
                -1, -1, -1,  4, -1, -1,     // next states for state 2
                -1, -1, -1,  1,  2, -1,     // next states for state 3
                -1,  8, -1,  4, -1,  5,     // next states for state 4
                -1, -1,  6,  7, -1, -1,     // next states for state 5
                -1, -1, -1,  7, -1, -1,     // next states for state 6
                -1,  8, -1,  7, -1, -1,     // next states for state 7
                -1,  8, -1, -1, -1, -1,     // next states for state 8
            };
            int state = 0, len = s.length();
            for (int i = 0; i < len; i ++) {
                InputType input = INVALID;
                char c = s[i];
                if (isspace(c)) {
                    input = SPACE;
                } else if (c == '+' || c == '-') {
                    input = SIGN;
                } else if (isdigit(c)) {
                    input = DIGIT;
                } else if (c == '.') {
                    input = DOT;
                } else if (c == 'e' || c == 'E') {
                    input = EXPONENT;
                }
                state = transitionTable[state][input];
                if (state == -1) {
                    return false;
                }
            }
            return state == 1 || state == 4 || state == 7 || state == 8;
        }
};

int main() {
    Solution solution;
    cout << solution.isNumber("005047e+6") << endl;
}



