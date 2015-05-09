/*=============================================================================
#     FileName: 128-LongestConsecutiveSequence.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-09 14:04:36
#      Version: 0.0.1
#   LastChange: 2015-05-09 17:41:12
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    //40ms
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size(), result = 1;
        if (len < 2) {
            return len;
        }
        unordered_set<int> set, visited_set;
        for (int i = 0; i < len; i ++) {
            set.insert(nums[i]);
        }

        for (int i = 0; i < len; i ++) {
            if (visited_set.find(nums[i]) != visited_set.end()) {
                continue;
            }
            visited_set.insert(nums[i]);
            int num = nums[i], sum = 1;
            while (set.find(-- num) != set.end()) {
                visited_set.insert(num);
            }
            sum += nums[i] - num - 1;
            num = nums[i];
            while (set.find(++ num) != set.end()) {
                visited_set.insert(num);
            }
            sum += num - nums[i] - 1;
            result = max(result, sum);
        }
        return result;

    }
};
