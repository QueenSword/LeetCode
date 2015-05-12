/*=============================================================================
#     FileName: 202-HappyNumber.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 21:38:55
#      Version: 0.0.1
#   LastChange: 2015-05-12 21:38:55
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <leetcode.h>
#include <unordered_set>

class Solution {
public:
    //11ms
    bool isHappy(int n) {
        if (n == 1) {
            return true;
        }
        unordered_set<int> nums;
        stringstream ss;
        
        while (true) {
            if (nums.find(n) != nums.end()) {
                return false;
            }
            nums.insert(n);
            string str;
            ss.clear();
            ss << n;
            ss >> str;
            n = 0;
            for (int i = 0; i < str.length(); i ++) {
                n += (str[i] - '0') * (str[i] - '0');
            }
            if (n == 1) {
                return true;
            }
        }

    }
};

int main() {
    Solution solution;
    printf("%d\n", solution.isHappy(7));
}
