/*=============================================================================
#     FileName: 40-CombinationSumII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-08 10:20:14
#      Version: 0.0.1
#   LastChange: 2015-04-08 10:43:28
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int> > result;
public:
    void dfs(vector<int> &candidates, int target, int level, vector<int> res) {
        if (target == 0) {
            result.push_back(res);
            return ;
        }
        if (level >= candidates.size() || target < 0) {
            return ;
        }
        int tmp = level + 1;
        while (tmp < candidates.size() && candidates[tmp] == candidates[level]) {
            tmp ++;
        }
        dfs(candidates, target, tmp, res);
        for (int i = 0; i < min(tmp - level, target / candidates[level]); i ++) {
            res.push_back(candidates[level]);
            dfs(candidates, target - (i + 1) * candidates[level], tmp, res);
        }
        return ;
    }
    
    //48ms
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        if (candidates.empty() || target <= 0) {
            return result;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> res;
        dfs(candidates, target, 0, res);
        return result;
    }
};

int main() {
    int nums[] = {10, 1, 2, 7, 6, 1, 5};
    vector<int> vec;
    for (int i = 0; i < sizeof(nums) / sizeof(int); i ++) {
        vec.push_back(nums[i]);
    }
    Solution solution;
    vector<vector<int> > result = solution.combinationSum2(vec, 8);
    for (int i = 0; i < result.size(); i ++) {
        for (int j = 0; j < result[i].size(); j ++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
