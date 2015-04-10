/*=============================================================================
#     FileName: 45-JumpGameII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-10 15:03:39
#      Version: 0.0.1
#   LastChange: 2015-04-10 15:03:39
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>

using namespace std;

class Solution {
public:
    //21ms
    int jump1(int A[], int n) {
        if (n < 2) {
            return 0;
        }
        if (A[0] >= n - 1) {
            return 1;
        }
        
        int curPos = 0, nextPos = 1, count = 0;
        while (curPos < n - 1) {
            if (A[curPos] == 0) {
                return 0;
            }

            nextPos = curPos + 1;
            for (int i = 1; i <= A[curPos]; i ++) {
                if (A[curPos + i] + curPos + i > A[nextPos] + nextPos) {
                    nextPos = curPos + i;
                }
                
            }
            if (A[nextPos] + nextPos >= n - 1) {
                return count + 2;
            }
            cout << curPos << " " << nextPos << endl;
            curPos = nextPos;
            count ++;
        }

        return 0;
    }
    //20ms
    int jump(int A[], int n) {
        if (n == 1) {
            return 0;
        }

        int curMax = 0, lastMax = 0, count = 0;
        for (int i = 0; i < n; i ++) {
            if (lastMax < i) {
                lastMax = curMax;
                count ++;
            }
            curMax = max(curMax, A[i] + i);
        }
        return count;
    }

};

int main() {
    int A[] = {5,2,1,2,5,2,6,8,1,9,3,5,8,0,2};
    Solution solution;
    cout << solution.jump(A, sizeof(A) / sizeof(int)) << endl;
    return 0;
}
