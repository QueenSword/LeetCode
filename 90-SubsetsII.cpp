/*=============================================================================
#     FileName: 90-SubsetsII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-30 15:00:50
#      Version: 0.0.1
#   LastChange: 2015-04-30 15:00:50
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int> > result;
public:
    void dfs(vector<int> ret, int level, vector<int> S) {
        int len = (int)S.size();
        if (level >= len) {
            result.push_back(ret);
            return ;
        }
        int end = level;
        while (end < len - 1 && S[end + 1] == S[end]) {
            end ++;
        }
        dfs(ret, end + 1, S);
        for (int i = 0; i < end - level + 1; i ++) {
            ret.push_back(S[level]);
            dfs(ret, end + 1, S);
        }
    }
    //15ms
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        if (S.empty()) {
            return result;
        }
        sort(S.begin(), S.end());
        vector<int> ret;
        dfs(ret, 0, S);

        return result;
    }

};

int main() {
    int nums[] = {1, 2, 2};
    vector<int> vec;
    for (int i = 0; i < 3; i ++) {
        vec.push_back(nums[i]);
        printf("%d ", vec[i]);
    }
    Solution solution;
    vector<vector<int> > result = solution.subsetsWithDup(vec);
    for (int i = 0; i < result.size(); i ++) {
        printf("%d\n", (int)result[i].size());
        for (int j = 0; j < result[0].size(); j ++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
