/*=============================================================================
#     FileName: 219-ContainsDuplicateII.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-06-18 15:31:17
#      Version: 0.0.1
#   LastChange: 2015-06-18 15:44:57
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    //68ms
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        int len = nums.size();
        for (int i = 0; i < len; i ++) {
            int num = nums[i];
            if (m.find(num) == m.end()) {
                m.insert(pair<int, int>(num, i));
            } else {
                if (i - m[num] <= k) {
                    return true;
                } else {
                    m[num] = i;
                }
            }
        }
        return false;
    }
};
