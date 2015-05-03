/*=============================================================================
#     FileName: 66-PlusOne.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-29 14:27:23
#      Version: 0.0.1
#   LastChange: 2015-04-29 14:27:23
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>

using namespace std;
class Solution {
public:

    //6ms
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) {
            return digits;
        }
        int len = digits.size();
        bool has_flow = false;
        for (int i = len - 1; i >= 0; i --) {
            if (i == len - 1) {
                digits[i] = digits[i] + 1;
            } else {
                digits[i] = digits[i] + (has_flow ? 1 : 0);
            }
            has_flow = digits[i] > 9 ? true : false;
            digits[i] %= 10;
            if (!has_flow) {
                break;
            }
        }
        if (has_flow) {
            digits.insert(digits.begin(), 1);    
        }
        return digits;
    }

};
