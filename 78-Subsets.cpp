/*=============================================================================
#     FileName: 78-Subsets.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-30 11:09:02
#      Version: 0.0.1
#   LastChange: 2015-04-30 11:09:02
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int> > result;
public:
    void dfs(vector<int> ret, int level, vector<int> nums) {
        result.push_back(ret);
        if (level == (int)nums.size()) {
            return ;
        }
        for (int i = level; i < (int)nums.size(); i ++) {
            ret.push_back(nums[i]);
            dfs(ret, i + 1, nums);
            ret.pop_back();
        }
    }

    //11ms
    vector<vector<int> > subsets(vector<int>& nums) {
        if (nums.empty()) {
            return result;
        }
        sort(nums.begin(), nums.end());
        vector<int> ret;
        dfs(ret, 0, nums);

        return result;
    }

};
