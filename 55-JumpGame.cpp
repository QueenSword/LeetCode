/*=============================================================================
#     FileName: 55-JumpGame.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-10 15:03:39
#      Version: 0.0.1
#   LastChange: 2015-04-11 11:18:09
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>

using namespace std;

class Solution {
public:
    //17ms
    bool canJump(int A[], int n) {
        if (n == 1) {
            return true;
        }

        int curMax = 0, lastMax = 0;
        for (int i = 0; i < n; i ++) {
            if (lastMax < i) {
                lastMax = curMax;
                if (curMax < i) {
                    return false;
                }
            }
            curMax = max(curMax, A[i] + i);
        }
        return true;
    }

};

int main() {
    int A[] = {3,2,1,0,4};
    Solution solution;
    cout << solution.canJump(A, sizeof(A) / sizeof(int)) << endl;
    return 0;
}
