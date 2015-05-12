/*=============================================================================
#     FileName: 179-LargestNumber.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 16:45:05
#      Version: 0.0.1
#   LastChange: 2015-05-12 18:46:08
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <leetcode.h>
#include <sstream>

class cmp {
public:
    bool operator() (const int &a, const int &b) {
        string s1, s2, tmp;
        stringstream ss;
        ss << a;
        ss >> s1;
        ss.clear();
        ss << b;
        ss >> s2;
        tmp = s1;
        s1 += s2;
        s2 += tmp;
        int len = s1.length();
        for (int i = 0; i < len; i ++) {
            if (s1[i] < s2[i]) {
                return true;
            } else if (s1[i] > s2[i]) {
                return false;
            }
        }
        return true;
    } 
};


class Solution {
public:
    //37ms
    string largestNumber(vector<int>& nums) {
        stringstream ss;
        int len = nums.size();
        if (len == 1) {
            ss << nums[0];
            return ss.str();
        }
        int count = 0;
        for (int i = 0; i < len; i ++) {
            count += nums[i];
        }
        if (!count) {
            return "0";
        }
        sort(nums.begin(), nums.end(), cmp());
        string result = "";
        for (int i = 0; i < len; i ++) {
            ss.clear();
            ss << nums[i];
            string temp;
            ss >> temp;
            result = temp + result;
        }
        return result;
    }
};

int main() {
    int num[] = {302};
    vector<int> nums;
    for (int i = 0; i < sizeof(num) / sizeof(int); i ++) {
        nums.push_back(num[i]);
    }
    Solution solution;
    printf("%s\n", solution.largestNumber(nums).c_str());


}
