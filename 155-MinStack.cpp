/*=============================================================================
#     FileName: 155-MinStack.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 11:35:10
#      Version: 0.0.1
#   LastChange: 2015-05-12 11:42:20
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <leetcode.h>

class MinStack {
public:
    
    //83ms
    vector<int> nums, index;

    void push(int x) {
        nums.push_back(x);
        if (nums.size() == 1) {
            index.push_back(0);
        } else {
            if (x <= nums[index.back()]) {
                index.push_back(nums.size() - 1);
            } else {
                index.push_back(index.back());
            }
        }
    }

    void pop() {
        nums.pop_back();
        index.pop_back();
    }

    int top() {
        return nums.back();
    }

    int getMin() {
        return nums[index.back()];
    }
};
