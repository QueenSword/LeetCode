/*=============================================================================
#     FileName: 157-ReadNCharactersGivenRead4.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-06-19 08:52:14
#      History:
=============================================================================*/

#include <leetcode.h>

int read4(char *buf) {
    return sizeof(buf);
}

class Solution {
    int read(char *buf, int n) {
        int len = 0, m;
        while (len + 4 <= n) {
            m = read4(buf + len);
            len += m;
            if (m < 4 || len == n) {
                return len;
            }
        }
        char *remain = new char[5];
        m = min(read4(remain), n - len);
        for (int i = 0; i < m; i ++) {
            buf[len ++] = remain[i];
        }
        delete remain;

        return len;
    }

};
