/*=============================================================================
#     FileName: 16-3SumClosest.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-05 05:18:02
#      Version: 0.0.1
#   LastChange: 2015-04-06 08:41:06
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <vector>

using namespace std;

class Solution {
public:
    //20ms
    int threeSumClosest(vector<int> &num, int target) {
        int closet = num[0] + num[1] + num[2];
        vector<int> temp(3, 0);
        if (num.size() < 3) {
            return closet;
        }

        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 2; i ++) {
            temp[0] = num[i];
            int l = i + 1, r = num.size() - 1;
            while (l < r) {
                int deta = num[i] + num[l] + num[r] - target;
                if (deta == 0) {
                    return target;
                } else if (deta > 0) {
                    if (deta < abs(closet - target)) {
                        closet = deta + target;
                    }
                    r --;
                } else {
                    if (-deta < abs(closet - target)) {
                        closet = deta + target;
                    }
                    l ++;
                }
            }
        }
        return closet;
    }
};

int main() {
    /*int num[] = {0, 0, 0};
    vector<int> vec;
    for (int i = 0; i < sizeof(num) / sizeof(int); i ++) {
        vec.push_back(num[i]);
    }
    Solution solution;
    solution.threeSum(vec);*/
    return 0;
}
