/*=============================================================================
#     FileName: 89-GrayCode.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-06-19 14:16:12
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    //8ms
    void dfs(vector<int> &result, int n) {
        if (n == 1) {
            result.clear();
            result.push_back(0);
            result.push_back(1);
            return ;
        }
        dfs(result, n - 1);
        int len = result.size();
        vector<int> temp(2 * len, 0);
        for (int i = 0; i < len; i += 2) {
            temp[2 * i] = 2 * result[i];
            temp[2 * i + 1] = 2 * result[i] + 1;
            temp[2 * i + 2] = 2 * result[i + 1] + 1;
            temp[2 * i + 3] = 2 * result[i + 1];
        }
        result.clear();
        for (int i = 0; i < 2 * len; i ++) {
            result.push_back(temp[i]);
        }
    }

    vector<int> grayCode(int n) {
        vector<int> result;
        dfs(result, n);
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> result = solution.grayCode(3);
    for (int i = 0; i < result.size(); i ++) {
        cout << result[i] << " ";
    }
    cout << endl;
}
