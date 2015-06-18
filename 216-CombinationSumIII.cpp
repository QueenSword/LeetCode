/*=============================================================================
#     FileName: 216-CombinationSumIII.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-06-18 13:16:39
#      Version: 0.0.1
#   LastChange: 2015-06-18 13:33:57
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //0ms
    void dfs(vector<vector<int> > &result, vector<int> &vec, int k, int n,int cur) {
        if (vec.size() == k) {
            if (n == 0) {
                result.push_back(vec);
            }
            return ;
        }
        if (n <= 0) {
            return ;
        }
        for (int i = cur + 1; i <= 9; i ++) {
            vec.push_back(i);
            dfs(result, vec, k, n - i, i);
            vec.pop_back();
        }
        return ;
    }


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > result;
        vector<int> vec;
        dfs(result, vec, k, n, 0);
        return result;
    }
};
