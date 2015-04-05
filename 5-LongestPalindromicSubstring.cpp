/*=============================================================================
#     FileName: 5-LongestPalindromicSubstring.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-04 22:19:05
#      Version: 0.0.1
#   LastChange: 2015-04-04 22:19:05
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //13ms
    string longestPalindrome(string s) {
        if (s == "") {
            return "";
        }
        string temp = "$";
        for (int i = 0; i < s.length(); i ++) {
            temp += s[i];
            temp += "#";
        }
        s = temp;
        vector<int> p(s.length(), 1);
        p[1] = 1;
        int id = 1, mx = 1, maxPos = 1;
        for (int i = 2; i < s.length(); i ++) {
            if (p[2*id - i] <= mx - i + 1) {
                p[i] = p[2*id - i];
                
            } else {
            
            p[i] = mx - i + 1;
            }
            
            while((i - p[i] >= 0) && (i + p[i] < s.length()) && s[i + p[i]] == s[i - p[i]]) {
                p[i] ++;
            }
            if (i + p[i] - 1 > mx) {
                mx = i + p[i] - 1;
                id = i;
            }
        }
        for (int i = 0; i < s.length(); i ++) {
            if (p[i] > p[maxPos]) {
                maxPos = i;
            }
        }
        s = s.substr(maxPos - p[maxPos] + 1, 2*p[maxPos] - 1);
        string result = "";
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] != '#') {
                result += s[i];
            }
        }
        
        return result;

    }
};

int main() {
    Solution solution;
    cout << solution.longestPalindrome("bb") << endl;
    return 0;
}
