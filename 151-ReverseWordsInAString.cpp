/*=============================================================================
#     FileName: 151-ReverseWordsInAString.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 09:54:49
#      Version: 0.0.1
#   LastChange: 2015-05-12 09:54:49
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    void reverse_string(string &s, int start, int end) {
        int i = start, j = end;
        while (i < j) {
            swap(s[i ++], s[j --]);
        }
        return ;
    }

    void pre_process(string &s) {
        int len = s.length();
        if (len == 0 || s == " ") {
            s = "";
            return ;
        }
        int i = 0, j = len - 1;
        while (i < len && s[i] == ' ') {
            i ++;
        }
        while (j >= 0 && s[j] == ' ') {
            j --;
        }
        if (i > j) {
            s = "";
            return ;
        }
        s = s.substr(i, j - i + 1);
        for ()

        return ;
    }

    void reverseWords(string &s) {
        int len = s.length();
        if (len = 0 || s == " ") {
            s = ""
            return ;
        }
        


        int start = 0, end;
        while (start < len) {
            while (s[start] == ' ') {
                start ++;
            }
            end = start;
            while (end < len && s[end] != ' ') {
                end ++;
            }
            reverse_string(s, start, end - 1);
            start = end;
        }
        return ;
    }

};
