/*=============================================================================
#     FileName: 228-SummaryRanges.cpp
#         Desc: Accepted, 0ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-07-19 22:39:23
#      History:
=============================================================================*/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int len = nums.size();
        if (len == 0) {
            return result;
        }
        int start = 0, end;
        stringstream ss;
        while (start < len) {
            end = start + 1;
            while (end < len && nums[end] == nums[end - 1] + 1) {
                end ++;
            }
            if (end == start + 1) {
                ss.str("");
                ss << nums[start];
                result.push_back(ss.str());
            } else {
                ss.str("");
                ss << nums[start];
                string s = ss.str();
                ss.str("");
                ss << nums[end - 1];
                s = s + "->" + ss.str();
                result.push_back(s);
            }
            start = end;
        }
        return result;
    }
};

int main() {
    int num[] = {0, 1, 2, 4, 5, 7};
    vector<int> nums;
    for (int i = 0; i < int(sizeof(num) / sizeof(int)); i ++ ) {
        nums.push_back(num[i]);
    }
    Solution solution;
    vector<string> result = solution.summaryRanges(nums);
    for (int i = 0; i < result.size(); i ++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
