/*=============================================================================
#     FileName: 13-RomanToInteger.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-05 04:22:51
#      Version: 0.0.1
#   LastChange: 2015-04-05 04:53:46
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <map>

using namespace std;


class Solution {
public:

    //89ms
    int romanToInt(string s) {
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int result = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (i == s.length() - 1 || m[s[i]] >= m[s[i + 1]]) {
                result += m[s[i]];
            } else {
                result -= m[s[i]];
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.romanToInt("MCMXCVI") << endl;
    return 0;
}
