/*=============================================================================
#     FileName: 22-GenerateParentheses.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-06 13:58:44
#      Version: 0.0.1
#   LastChange: 2015-04-06 13:58:44
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> result;

public:
    //4ms
    void dfs(int left, int right, int n, string res) {
        if (left == n) {
            for (int i = 0; i < left - right; i ++) {
                res += ')';
            }
            result.push_back(res);
            return ;
        }
        for (int i = 0; i < n - left; i ++) {
            string temp = res;
            for (int j = 0; j < i + 1; j ++) {
                temp += "(";
            }
            temp +=")";
            dfs(left + i + 1, right + 1, n, temp);
        }
        if (left > right) {
            dfs(left, right + 1, n, res + ")");
        }
        return ;
    }

    vector<string> generateParenthesis(int n) {
        if (n < 1) {
            return result;
        }
        dfs(0, 0, n, "");
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> result = solution.generateParenthesis(3);
    for (int i = 0; i < result.size(); i ++) {
        cout << result[i] << " ";
    }
    cout << endl;
}
