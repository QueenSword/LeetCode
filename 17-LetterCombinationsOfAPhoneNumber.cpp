/*=============================================================================
#     FileName: 17-LetterCombinationsOfAPhoneNumber.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-06 09:36:04
#      Version: 0.0.1
#   LastChange: 2015-04-06 09:36:04
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> result;
    map<char, string> m;
public:
    
    void dfs(string digits, string res) {
        if (digits == "") {
            result.push_back(res);
            return ;
        }
        for (int i = 0; i < m[digits[0]].length(); i ++) {
            dfs(digits.substr(1, digits.length() - 1), res + m[digits[0]][i]);
        }
    }
    
    void initMap() {
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        m['*'] = "+";
    }

    //2ms
    vector<string> letterCombinations(string digits) {
        if (digits == "") {
            return result;
        }
        initMap();
        string res;
        dfs(digits, res);
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> result = solution.letterCombinations("23");
    for (int i = 0; i < result.size(); i ++) {
        cout << result[i] << endl;
    }

    return 0;
}
