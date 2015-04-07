/*=============================================================================
#     FileName: 35-SearchInsertPosition.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-07 15:38:51
#      Version: 0.0.1
#   LastChange: 2015-04-07 15:38:51
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>

using namespace std;

class Solution {
public:
    //19ms
    int searchInsert(int A[], int n, int target) {
        int pos = 0;
        while (pos < n && A[pos] < target) {
            pos ++;
        }
        return pos;
    }
};

int main() {
    
}
