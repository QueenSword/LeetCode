/*=============================================================================
#     FileName: 97-InterleavingString.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-04 21:07:43
#      Version: 0.0.1
#   LastChange: 2015-05-04 21:19:26
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    //25ms
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if (len1 + len2 != len3) {
            return false;
        }
        if (len1 == 0) {
            return s2 == s3;
        }
        if (len2 == 0) {
            return s1 == s3;
        }

        vector<vector<bool> > dp(len1 + 1, vector<bool>(len2 + 1, true));
        for (int i = 1; i <= len1; i ++) {
            dp[i][0] = dp[i - 1][0] ? s1[i - 1] == s3[i - 1] : false;
        }
        for (int j = 1; j <= len2; j ++) {
            dp[0][j] = dp[0][j - 1] ? s2[j - 1] == s3[j - 1] : false;
        }
        for (int i = 1; i <= len1; i ++) {
            for (int j = 1; j <= len2; j ++) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[len1][len2];
    }
};
