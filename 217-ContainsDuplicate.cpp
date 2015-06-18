/*=============================================================================
#     FileName: 217-ContainsDuplicate.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-06-18 13:34:24
#      Version: 0.0.1
#   LastChange: 2015-06-18 15:29:49
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    //48ms
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (auto num: nums) {
            if (set.find(num) != set.end()) {
                return true;
            }
            set.insert(num);
        }
        return false;
    }
};
