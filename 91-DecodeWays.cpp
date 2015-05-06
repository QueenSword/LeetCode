/*=============================================================================
#     FileName: 91-DecodeWays.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-03 16:58:31
#      Version: 0.0.1
#   LastChange: 2015-05-03 16:58:31
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    //11ms
    int numDecodings(string s) {
        if (s == "") {
            return 0;
        } else if (s.length() == 1) {
            return s[0] == '0' ? 0 : 1;
        }
        vector<int> dp(s.length() + 1, 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= (int)s.length(); i ++) {
            char a = s[i - 2], b = s[i - 1];
            if (a == '0') {
                if (b == '0' || i == 2) {
                    return 0;
                }
                dp[i] = dp[i - 1];
            } else if (a == '1') {
                if (b == '0') {
                    dp[i] = dp[i - 2];
                } else {
                    dp[i] = dp[i - 2] + dp[i - 1];
                } 
            } else if (a == '2') {
                if (b == '0') {
                    dp[i] = dp[i - 2];
                } else if (b < '7') {
                    dp[i] = dp[i - 2] + dp[i - 1];
                } else {
                    dp[i] = dp[i - 1];
                }
            } else {
                if (b == '0') {
                    return 0;
                }
                dp[i] = dp[i - 1];
            }
        }
        return dp[s.length()];
    }

};

int main() {
    Solution solution;
    printf("%d \n", solution.numDecodings("11"));
}
