/*=============================================================================
#     FileName: 229-MajorityElementII.cpp
#         Desc: AC
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-07-28 17:06:06
#      History:
=============================================================================*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            vector<int> result;
            int len = nums.size();
            int num1 = 0, num2 = 0, count1 = 0, count2 = 0;
            for (int i = 0; i < len; i ++) {
                int num = nums[i];
                if (count1 == 0 || num1 == num) {
                    num1 = num;
                    count1 ++;
                } else if (count2 == 0 || num2 == num) {
                    num2 = num;
                    count2 ++;
                } else {
                    count1 --;
                    count2 --;
                }
            }
            count1 = 0, count2 = 0;
            for (int i = 0; i < len; i ++) {
                int num = nums[i];
                if (num == num1) {
                    count1 ++;
                } else if (num == num2) {
                    count2 ++;
                }
            }
            if (count1 > len / 3) {
                result.push_back(num1);
            }
            if (count2 > len / 3) {
                result.push_back(num2);
            }
            return result;
        }
};

int main() {
    int num[] = {1, 1, 1, 3, 3, 2, 2, 2};
    vector<int> nums;
    for (int i = 0; i < (int)(sizeof(num) / sizeof(int)); i ++) {
        nums.push_back(num[i]);
    }
    Solution solution;
    vector<int> result = solution.majorityElement(nums);
    for (int i = 0; i < int(result.size()); i ++) {
        cout << result[i] << "  ";
    }
    cout << endl;
    return 0;
}
