/*=============================================================================
#     FileName: 164-MaximumGap.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 11:54:45
#      Version: 0.0.1
#   LastChange: 2015-06-17 21:29:28
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>
#include <math.h>
#include <limits>

using namespace std;

class Solution {
public:
    //24ms
    int maximumGap(vector<int>& nums) {
        int len = nums.size(), MIN = INT_MAX, MAX = INT_MIN;
        if (len < 2) {
            return 0;
        }
        for (int i = 0; i < len; i ++) {
            MIN = min(MIN, nums[i]);
            MAX = max(MAX, nums[i]);
        }
        int deta = ceil(double(MAX - MIN + 1) / len);
        vector<vector<int> > bucket(len);
        for (int i = 0; i < len; i ++) {
            int pos = (nums[i] - MIN) / deta;
            if (bucket[pos].empty()) {
                bucket[pos].push_back(nums[i]);
                bucket[pos].push_back(nums[i]);
            } else {
                bucket[pos][0] = max(bucket[pos][0], nums[i]);
                bucket[pos][1] = min(bucket[pos][1], nums[i]);
            }
        }
        int prev = 0, result = INT_MIN;
        for (int i = 1; i < len; i ++) {
            if (bucket[i].empty()) {
                continue;
            }
            result = max(bucket[i][1] - bucket[prev][0], result);
            prev = i;
        }

        return result;
    }

};
