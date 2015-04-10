/*=============================================================================
#     FileName: 42-TrappingRainWater.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-08 11:35:56
#      Version: 0.0.1
#   LastChange: 2015-04-08 11:35:56
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    //24ms Binary Search will be faster
    int trap(int A[], int n) {
        if (n < 3) {
            return 0;
        }
        int result = 0;
        vector<int> points;
        int tmp = 1;
        while (tmp < n) {
            while (tmp < n && A[tmp] >= A[tmp - 1]) {
                tmp ++;
            }
            points.push_back(tmp - 1);
            while (tmp < n && A[tmp] <= A[tmp - 1]) {
                tmp ++;
            }
        }
        
        vector<int>::iterator it = points.begin() + 1;
        bool flag = true;
        while (flag) {
            flag = false;
            it = points.begin() + 1;
            while (it < points.end() - 1) {

            if (A[*(it)] <= A[*(it - 1)] && A[*it] <= A[*(it + 1)]) {
                points.erase(it);
                flag = true;
            } else {
                it ++;
            }
            }
        }
        
        for (int i = 1; i < points.size(); i ++) {
            int height = min(A[points[i]], A[points[i - 1]]);
            for (int j = points[i - 1] + 1; j < points[i]; j ++) {
                
                result += height > A[j] ? height - A[j] : 0;
            }
        }
        return result;
    }
};

int main() {
    int A[] = {5, 2, 1, 2, 1, 5};
    Solution solution;
    cout << solution.trap(A, 6) << endl;
    return 0;
}
