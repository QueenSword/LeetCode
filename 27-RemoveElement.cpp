/*=============================================================================
#     FileName: 27-RemoveElement.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-06 23:46:50
#      Version: 0.0.1
#   LastChange: 2015-04-06 23:46:50
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    //8ms
    int removeElement(int A[], int n, int elem) {
        int count = 0;
        for (int i = 0; i < n; i ++) {
            if (A[i] != elem) {
                A[count ++] = A[i];
            }
        }
        return count;
    }
};

int main() {
    return 0;
}
