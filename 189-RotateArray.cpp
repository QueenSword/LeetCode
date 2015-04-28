/*=============================================================================
#     FileName: 189-RotateArray.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-15 12:48:06
#      Version: 0.0.1
#   LastChange: 2015-04-15 12:48:06
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>

using namespace std;

class Solution {
public:
    void rotateBlock(int nums[], int low, int high) {
        while (low < high) {
            swap(nums[low ++], nums[high --]);
        }
        return ;
    }
    //31ms
    void rotate(int nums[], int n, int k) {
        k %= n;
        rotateBlock(nums, 0, n - 1);
        rotateBlock(nums, 0, k - 1);
        rotateBlock(nums, k, n - 1);
        return ;
    }
};

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    Solution solution;
    solution.rotate(nums, 7, 3);
    for (int i = 0; i < 7; i ++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
