/*=============================================================================
#     FileName: 93-RestoreIPAddresses.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-03 20:23:02
#      Version: 0.0.1
#   LastChange: 2015-05-04 19:57:24
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> result;
public:
    //14ms 
    bool less(string a, string b) {
        while (a != "" && a[0] == '0') {
            a = a.substr(1, a.length() - 1);
        }
        while (b != "" && b[0] == '0') {
            b = b.substr(1, b.length() - 1);
        }
        int len1 = a.length(), len2 = b.length();
        if (len1 < len2) {
            return true;
        } else if (len1 > len2) {
            return false;
        }
        for (int i = 0; i < len1; i ++) {
            if (a[i] < b[i]) {
                return true;
            } else if (a[i] > b[i]) {
                return false;
            }
        }
        return false;
    }

    void dfs(string ret, int level, string s) {
        if (level == 3) {
            if (s[0] == '0' && s.length() > 1) {
                return ;
            }
            if (s != "" && less(s, "256")) {
                ret += ".";
                ret += s;
                printf("%s %s %d\n", s.c_str(), ret.c_str(), less(s, "256"));
                result.push_back(ret.substr(1, ret.length() - 1));
            } 
            return ;
        }
        if (s[0] == '0') {
            dfs(ret + "." + s[0], level + 1, s.substr(1, s.length() - 1));
            return ;
        }
        for (int i = 1; i < s.length() + level - 2; i ++) {
            if (less(s.substr(0, i), "256")) {

                dfs(ret + "." + s.substr(0, i), level + 1, s.substr(i, s.length() - i));
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.length() < 4) {
            return result;
        }
        string ret = "";
        dfs(ret, 0, s);
        return result;
    }

};

int main() {
    Solution solution;
    vector<string> result = solution.restoreIpAddresses("25525511135");
    printf("===========\n");
    for (int i = 0; i < result.size(); i ++) {
        printf("%s\n", result[i].c_str());
    }
    return 0;
}
