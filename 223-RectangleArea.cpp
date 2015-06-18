/*=============================================================================
#     FileName: 223-RectangleArea.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-06-18 21:39:55
#      History:
=============================================================================*/

#include <iostream>

using namespace std;

class Solution {
public:
    //24ms
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A, E), right = min(C, G), up = min(D, H), down = max(B, F);
        int total = (C - A) * (D - B) + (G - E) * (H - F);
        if (left >= right || up <= down) {
            return total;
        }
        return total - (right - left) * (up - down);
    }
};
