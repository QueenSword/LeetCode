/*=============================================================================
#     FileName: 215-KthLargestElementInAnArray.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-06-18 11:49:29
#      Version: 0.0.1
#   LastChange: 2015-06-18 11:49:29
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    //14ms
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (auto num: nums) {
            q.push(num);
        }
        int result;
        for (int i = 0; i < k; i ++) {
            result = q.top();
            q.pop();
        }
        return result;
    }
};
