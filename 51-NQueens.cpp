/*=============================================================================
#     FileName: 51-NQueens.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-10 20:58:45
#      Version: 0.0.1
#   LastChange: 2015-04-10 20:58:45
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>

using  namespace std;


class Solution {
private:
    vector<vector<string> > result;
public:
    //62ms
    bool isValid(vector<int> res, int level, int x) {
        for (int i = 0; i < level; i ++) {
            if (res[i] == x || res[i] - x == i - level || res[i] - x == level - i) {
                return false;
            }
        }
        return true;
    }
    void dfs(vector<int> res, int level, int n) {
        if (level == n) {
            for (int i = 0; i < n; i ++) {
                cout << res[i] << " ";
            }
            cout << endl;
            vector<string> vec;
            for (int i = 0; i < n; i ++) {
                string s = "";
                for (int j = 0; j < n; j ++) {
                    if (res[i] == j) {
                        s += 'Q';
                    } else {
                        s += '.';
                    }
                }
                vec.push_back(s);
            }
            result.push_back(vec);
            return ;
        }
        for (int i = 0; i < n; i ++) {
            if (isValid(res, level, i)) {
                res[level] = i;
                dfs(res, level + 1, n);
            }    
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<int> res(n);
        dfs(res, 0, n);   
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<string> > result = solution.solveNQueens(4);
    for (int i = 0; i < result.size(); i ++) {
        for (int j = 0; j < result[i].size(); j ++) {
            cout << result[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}
