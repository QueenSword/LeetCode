/*=============================================================================
#     FileName: 48-RotateImage.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-10 16:35:29
#      Version: 0.0.1
#   LastChange: 2015-04-10 16:35:29
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    //6ms
	void rotate(vector<vector<int> > &matrix) {
		int maxIndex = matrix.size() - 1;
		for (int i = 0;i < matrix.size() / 2; i ++) {
			for (int j = i; j < matrix.size() - i - 1; j ++) {
				int temp = matrix[maxIndex - j][i];
				matrix[maxIndex - j][i] = matrix[maxIndex - i][maxIndex - j];
				matrix[maxIndex - i][maxIndex - j] = matrix[j][maxIndex - i];
				matrix[j][maxIndex - i] = matrix[i][j];
				matrix[i][j] = temp;
				
			}
		}
	}
};

int main() {

    return 0;
}
