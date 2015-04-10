/*=============================================================================
#     FileName: 47-PermutationsII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-10 16:21:26
#      Version: 0.0.1
#   LastChange: 2015-04-10 16:21:26
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    //33ms
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        if (num.empty()) {
            return result;
        }
        int len = num.size();
        if (len == 1) {
            result.push_back(num);
            return result;
        }
        sort(num.begin(), num.end());
        while (true) {
            result.push_back(num);
            int pos1 = len - 2, pos2 = len - 1;
            while (pos1 >= 0 && num[pos1] >= num[pos1 + 1]) {
                pos1 --;
            }
            if (pos1 == -1) {
                break;
            }
            while (num[pos2] <= num[pos1]) {
                pos2 --;
            }
            swap(num[pos1], num[pos2]);
            int l = pos1 + 1, r = len - 1;
            while (l < r) {
                swap(num[l ++], num[r --]);
            }
        }
        return result;

    }
};

int main() {
    int nums[] = {1, 2, 1};
    vector<int> num;
    for (int i = 0; i < sizeof(nums) / sizeof(int); i ++) {
        num.push_back(nums[i]);
    }
    Solution solution;
    vector<vector<int> > result = solution.permuteUnique(num);
    for (int i = 0; i < result.size(); i ++) {
        for (int j = 0; j < result[0].size(); j ++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
