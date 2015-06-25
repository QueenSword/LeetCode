/*=============================================================================
#     FileName: 186-ReverseWordsInAStringII.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-06-25 23:25:18
#      History:
=============================================================================*/

#include <leetcode.h>

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
