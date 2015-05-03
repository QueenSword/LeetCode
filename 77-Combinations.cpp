/*=============================================================================
#     FileName: 77-Combinations.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-30 10:53:09
#      Version: 0.0.1
#   LastChange: 2015-04-30 10:53:09
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int> > result;

public:
    void dfs(vector<int> ret, int n, int k) {
        if (k == 0) {
            result.push_back(ret);
            return ;
        }
        if (ret.empty()) {
            for (int i = 1; i <= n - k + 1; i ++) {
                ret.push_back(i);
                dfs(ret, n, k - 1);
                ret.pop_back();
            }
        } else {
            for (int i = ret.back() + 1; i <= n - k + 1; i ++) {
                ret.push_back(i);
                dfs(ret, n, k - 1);
                ret.pop_back();
            }
        }
        return ;
    }
    //16ms
    vector<vector<int> > combine(int n, int k) {
        vector<int> ret;
        if (k == 0 || n < 1) {
            return result;
        }
        dfs(ret, n, k);
        return result;
    }

};

int main() {
    Solution solution;
    vector<vector<int> > ret = solution.combine(4, 2);
    for (int i = 0; i < (int)ret.size(); i ++) {
        for (int j = 0; j < (int)ret[i].size(); j ++) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }
    return 0;
}
