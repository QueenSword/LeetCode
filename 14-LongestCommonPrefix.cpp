/*=============================================================================
#     FileName: 14-LongestCommonPrefix.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-05 05:06:51
#      Version: 0.0.1
#   LastChange: 2015-04-05 05:06:51
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:

    //7ms
    string longestCommonPrefix(vector<string> &strs) {
        string result = "";
        int minLength = INT_MAX;
        if (strs.size() == 0) {
            return result;
        }
        for (int i = 0; i < strs.size(); i ++) {
            if (strs[i] == "") {
                return result;
            }
            minLength = min(minLength, (int)(strs[i].length()));
        }
        for (int i = 0; i < minLength; i ++) {
            for (int j = 1; j < strs.size(); j ++) {
                if (strs[j][i] != strs[j - 1][i]) {
                    return result;
                }
            }
            result += strs[0][i];
        } 
        return result;
    }
};

int main() {
    return 0;
}
