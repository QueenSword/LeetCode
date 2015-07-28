/*=============================================================================
#     FileName: 229-MajorityElementII.cpp
#         Desc: 
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
        if (len == 0) {
            return result;
        }
        /*if (len < 3) {*/
            //result.push_back(nums[0]);
            //if (len == 2 && nums[0] != nums[1]) {
                //result.push_back(nums[1]);
            //}
            //return result;
        /*}*/
        map<int, int> numMap;
        map<int, int>::iterator it;
        for (int i = 0; i < len; i ++) {
            int num = nums[i];
            if (numMap.size() < 2) {
                if (numMap.find(num) == numMap.end()) {
                    numMap.insert(pair<int, int>(num, 1));
                } else {
                    numMap[num] ++;
                }
            } else {
                for (it = numMap.begin(); it != numMap.end(); it ++) {
                    numMap[it->first] --;
                    if (numMap[it->first] == 0) {
                        numMap.erase(it);
                        numMap.insert(pair<int, int>(num, 1));
                    }
                }
            }
        }
        for (it = numMap.begin(); it != numMap.end(); it ++) {
            result.push_back(it->first);
        }
        return result;
    }
};

int main() {
    int num[] = {1, 1, 2, 2, 3, 5, 6, 1};
    vector<int> nums;
    for (int i = 0; i < sizeof(num) / sizeof(int); i ++) {
        nums.push_back(num[i]);
    }
    Solution solution;
    vector<int> result = solution.majorityElement(nums);
    for (int i = 0; i < result.size(); i ++) {
        cout << result[i] << "  ";
    }
    cout << endl;
    return 0;
}
