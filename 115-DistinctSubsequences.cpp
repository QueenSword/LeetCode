/*=============================================================================
#     FileName: 115-DistinctSubsequences.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-08 18:37:31
#      Version: 0.0.1
#   LastChange: 2015-05-08 19:02:40
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    //38ms
    int numDistinct(string s, string t) {
        if (t == "") {
            return 1;
        }
        int len1 = s.length(), len2 = t.length();
        if (len1 < len2) {
            return false;
        }
        vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 0; i <= len2; i ++) {
            dp[0][i] = 0;
        }
        for (int i = 0; i <= len1; i ++) {
            dp[i][0] = 1;
        }
        for (int j = 1; j <= len2; j ++) {
            for (int i = j; i <= len1; i ++) {
                dp[i][j] = s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] + dp[i - 1][j]: dp[i - 1][j];
            }
        }
        return dp[len1][len2];
    }

};

int main() {
    Solution solution;
    printf("%d\n", solution.numDistinct("rabbbit", "rabbit"));
}
