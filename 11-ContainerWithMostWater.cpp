/*=============================================================================
#     FileName: 11-ContainerWithMostWater.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-05 03:36:38
#      Version: 0.0.1
#   LastChange: 2015-04-05 03:36:38
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

    //36ms
    int maxArea(vector<int> &height) {
        int i = 0, j = height.size() - 1, result = min(height[i], height[j]) * (j - i);
        while (i < j) {
            if (height[i] <= height[j]) {
                int temp = i;
                while (temp < j && height[temp] <= height[i]) {
                    temp ++;
                }
                if (temp >= j) {
                    break;
                }
                i = temp;
                result = max(result, min(height[i], height[j]) * (j - i));
            } else {
                int temp = j;
                while (temp > i && height[temp] <= height[j]) {
                    temp --;
                }
                if (temp <= i) {
                    break;
                }
                j = temp;
                result = max(result, min(height[i], height[j]) * (j - i));
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    int num[] = {2, 1, 4, 5, 32, 1, 4, 5, 3};
    vector<int> height;
    for (int i = 0; i < sizeof(num) / sizeof(int); i ++) {
        height.push_back(num[i]);
    }
    cout << solution.maxArea(height) << endl;
    return 0;
}
