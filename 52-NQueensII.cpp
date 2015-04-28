/*=============================================================================
#     FileName: 52-NQueensII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-10 20:58:45
#      Version: 0.0.1
#   LastChange: 2015-04-10 22:46:01
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>

using  namespace std;


class Solution {
private:
    int count;
public:
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
            count ++; 
            return ;
        }
        for (int i = 0; i < n; i ++) {
            if (isValid(res, level, i)) {
                res[level] = i;
                dfs(res, level + 1, n);
            }    
        }
    }
    
    //51ms
    int totalNQueens(int n) {
        count = 0;
        vector<int> res(n);
        dfs(res, 0, n);   
        return count;
    }
};

int main() {
    Solution solution;
    cout << solution.totalNQueens(4) << endl;
    return 0;
}
