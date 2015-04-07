/*=============================================================================
#     FileName: 31-NextPermutation.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-07 14:07:36
#      Version: 0.0.1
#   LastChange: 2015-04-07 14:07:36
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    //23ms
    void nextPermutation(vector<int> &num) {
        int len = num.size(), pos1 = len -1, pos2 = len - 1;
        while (pos1 > 0 && num[pos1] <= num[pos1 - 1]) {
            pos1 --;
        }
        if (pos1 == 0) {
            sort(num.begin(), num.end());
            return ;
        }
        pos1 --;
        while (num[pos2] <= num[pos1]) {
            pos2 --;
        }
        swap(num[pos1], num[pos2]);
        int l = pos1 + 1, r = len - 1;
        while (l < r) {
            swap(num[l ++], num[r --]);
        }
        return ;
    }
};

int main() {
    int nums[] = {1, 2, 3};
    vector<int> num;
    for (int i = 0; i < sizeof(nums) / sizeof(int); i ++) {
        num.push_back(nums[i]);
    }
    Solution solution;
    solution.nextPermutation(num);
    for (int i = 0; i < num.size(); i ++) {
        cout << num[i] << " ";
    }
    cout << endl;
    return 0;
}
