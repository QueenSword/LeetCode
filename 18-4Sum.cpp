/*=============================================================================
#     FileName: 18-4Sum.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-06 10:13:29
#      Version: 0.0.1
#   LastChange: 2015-04-06 10:13:29
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    //118ms
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        vector<int> temp(4, 0);
        if (num.size() < 4) {
            return result;
        }
        
        sort(num.begin(), num.end());
        temp[0] = num[0]; 
        temp[1] = num[1];
        for (int i = 0; i < num.size() - 3; i ++) {
            if (i != 0 && temp[0] == num[i]) {
                continue;
            }
            temp[0] = num[i];
            for (int j = i + 1; j < num.size() - 2; j ++) {
                if (j != i + 1 && temp[1] == num[j]) {
                    continue;
                }
                temp[1] = num[j];
                int l = j + 1, r = num.size() - 1;
                while (l < r) {
                    int sum = num[i] + num[j] + num[l] + num[r];
                    if (sum == target) {
                        temp[2] = num[l];
                        temp[3] = num[r];
                        result.push_back(temp);
                        l ++;
                        r --;
                        while (l < r && num[l] == num[l - 1]) {
                            l ++;
                        }
                        while (l < r && num[r] == num[r + 1]) {
                            r --;
                        }
                    } else if (sum > target) {
                        r --;
                    } else {
                        l ++;
                    }
                }
            }
        }

        return result;
        
    }
};

int main() {

    int nums[] = {1, 0, -1, 0, -2, 2};
    vector<int> num;
    for (int i = 0; i < sizeof(nums) / sizeof(int); i ++) {
        num.push_back(nums[i]);
    }
    Solution solution;
    vector<vector<int> > result = solution.fourSum(num, 0);
    for (int i = 0; i < result.size(); i ++) {
        for (int j = 0; j < result[i].size(); j ++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
