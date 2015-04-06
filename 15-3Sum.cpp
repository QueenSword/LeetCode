/*=============================================================================
#     FileName: 15-3Sum.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-05 05:18:02
#      Version: 0.0.1
#   LastChange: 2015-04-05 05:18:02
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    //73ms
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        vector<int> temp(3, 0);
        if (num.size() < 3) {
            return result;
        }

        sort(num.begin(), num.end());

        for (int i = 0; i < num.size() - 2; i ++) {
            if (result.size() > 0 && result.back()[0] == num[i]) {
                continue;
            }
            temp[0] = num[i];
            int l = i + 1, r = num.size() - 1;
            while (l < r) {
                if (num[l] + num[r] == -num[i]) {
                    temp[1] = num[l];
                    temp[2] = num[r];
                    result.push_back(temp);
                    l ++;
                    r --;
                    while (l < r && num[l] == num[l - 1]) {
                        l ++;
                    }
                    while (l < r && num[r] == num[r + 1]) {
                        r --;
                    }
                } else if (num[l] + num[r] > -num[i]) {
                    r --;
                } else {
                    l ++;
                }
            }
        }

        return result;
    }
};

int main() {
    int num[] = {0, 0, 0};
    vector<int> vec;
    for (int i = 0; i < sizeof(num) / sizeof(int); i ++) {
        vec.push_back(num[i]);
    }
    Solution solution;
    solution.threeSum(vec);
    return 0;
}
