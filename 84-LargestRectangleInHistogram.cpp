/*=============================================================================
#     FileName: 84-LargestRectangleInHistogram.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-30 12:52:24
#      Version: 0.0.1
#   LastChange: 2015-04-30 12:52:24
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    //memory litit exceeded
    /*int largestRectangleArea(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        int len = (int)height.size(), global_max = 0;
        if (len == 1) {
            return height[0];
        }
        vector<vector<int> > dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; i ++) {
            for (int j = i; j < len; j ++) {
                dp[i][j] = i == j ? height[i] : min(dp[i][j - 1], height[i]);
            }
        }
        for (int i = 0; i < len; i ++) {
            for (int j = i; j < len; j ++) {
                global_max = max(global_max, dp[i][j] * (j - i + 1));
            }
        }
        return global_max;
    }*/
    //24ms
    int largestRectangleArea(vector<int>& height) {
        stack<int> s;
        int maxArea = 0, len = height.size();
        for (int i = 0; i < len; i ++) {
            if (s.empty()) {
                s.push(i);
                continue;
            }
            while (!s.empty() && height[i] < height[s.top()]) {
                int pos = s.top();
                s.pop();
                if (s.empty()) {
                    maxArea = max(maxArea, height[pos] * i);
                } else {
                    maxArea = max(maxArea, height[pos] * (i - s.top() - 1));
                }
            }
            s.push(i);
        }
        
        while (!s.empty()) {
            int pos = s.top();
            s.pop();
            if (s.empty()) {
                maxArea = max(maxArea, len * height[pos]);
            } else {
                maxArea = max(maxArea, (len - s.top() - 1) * height[pos]);
            }
        }
        return maxArea;
   
    }
};

int main() {
    int nums[] = {2, 1, 2};
    vector<int> vec;
    for (int i = 0; i < sizeof(nums) / sizeof(int); i ++) {
        vec.push_back(nums[i]);
    }
    Solution solution;
    cout << solution.largestRectangleArea(vec) << endl;
}
