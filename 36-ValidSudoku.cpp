/*=============================================================================
#     FileName: 36-ValidSudoku.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-07 19:46:28
#      Version: 0.0.1
#   LastChange: 2015-04-07 19:46:28
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    //16ms
	bool isValidSudoku(vector<vector<char> > &board) {
		for (int i = 0; i < 9; i ++) {
			int count[9] = {0};
			for (int j = 0; j < 9; j ++) {
				if (board[i][j] != '.') {
					count[(int)(board[i][j] - '1')] ++;
				}
			}
			if (!isValid(count)) {
				return false;
			}
		}
		for (int i = 0; i < 9; i ++) {
			int count[9] = {0};
			for (int j = 0; j < 9; j ++) {
				if (board[j][i] != '.') {
					count[(int)(board[j][i] - '1')] ++;
				}
			}
			if (!isValid(count)) {
				return false;
			}
		}
		
		for (int i = 0; i < 9; i ++) {
			int count[9] = {0};
			int a = i / 3, b = i % 3;
			for (int j = 3 * a; j < 3 * a + 3; j ++) {
				for (int k = 3 * b; k < 3 * b + 3; k ++) {
					if (board[j][k] != '.') {
						count[(int)(board[j][k] - '1')] ++;
					}
				}
			
			}
			if (!isValid(count)) {
				return false;
			}
		}


		return true;
	}

	bool isValid(int A[]) {
		for (int i = 0; i < 9; i ++) {
			if (A[i] > 1) {
				return false;
			}
		}
		return true;
	
	}
};

int main() {
    return 0;
}
