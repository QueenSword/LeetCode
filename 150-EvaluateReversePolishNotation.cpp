/*=============================================================================
#     FileName: 150-EvaluateReversePolishNotation.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 09:27:09
#      Version: 0.0.1
#   LastChange: 2015-05-12 10:59:11
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include "leetcode.h"

class Solution {
public:
	void reverseWord(string &s,int start, int end) {
		int i = start, j = end;
		while (i < j) {
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			i ++;
			j --;
		}
		return ;
	}
    
    //17ms
	void reverseWords(string &s) {
		int start = 0, end = 0;
		while (s[start] == ' ') {
			start ++;
		}
		if (start == s.length()) {
			s = "";
			return ;
		}
		s = s.substr(start, s.length() - start);
		end = s.length() - 1;
		while (s[end] == ' ') {
			end --;
		}
		s = s.substr(0, end + 1);
		start = 0, end = 0;
		while (1) {
			while (end < s.length() && s[end] != ' ') {
				end ++;
			}
			if (end == s.length()) {
				reverseWord(s, start, end - 1);
				break;
			}
			reverseWord(s, start, end - 1);
			while (end < s.length() && s[end] == ' ') {
				end ++;
			}
			start = end;						
		}
		reverseWord(s, 0, s.length() - 1);
		for (int i = 0; i < s.length() - 1; i ++) {
			while (s[i] == ' ' && s[i + 1] == ' ') {
				deleteCharAtIndex(s, i + 1);
			}	
		}
		return ;
	}
	void deleteCharAtIndex(string &s, int index) {
		string temp = s.substr(0, index);
		temp = temp + s.substr(index + 1, s.length() - index - 1);
		s = temp;
	}

};

