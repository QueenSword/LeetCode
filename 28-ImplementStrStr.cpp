/*=============================================================================
#     FileName: 28-ImplementStrStr.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-06 23:54:13
#      Version: 0.0.1
#   LastChange: 2015-04-06 23:54:13
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <leetcode.h>

using namespace std;

class Solution {
public:
    
    int strStr(string haystack, string needle) {
        int len1 = haystack.size(), len2 = needle.size();
        if (len1 < len2) {
            return -1;
        }
        if (len1 == 0 || len2 == 0) {
            return 0;
        }
        vector<int> next(len2, 0);
        next[0] = -1;
        int i = 0, j = -1;
        while (i < len2 - 1) {
            if (j == -1 || needle[i] == needle[j]) {
                i ++;
                j ++;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
        for (int i = 0; i < len2; i ++) {
            printf("%d ", next[i]);
        }
        
        printf("\n");
        i = 0, j = 0;
        while (i < len1 & j < len2) {
            if (haystack[i] == needle[j]) {
                i ++;
                j ++;
            } else {
                printf("%d %d %d\n", i, j, next[j]);
                i += next[j];
            }
        }
        if (j == len2) {
            return i;
        }
        return -1;
    }
};

int main() {
    Solution solution;
    printf("%d\n", solution.strStr("babababababb", "bababb"));
    //printf("%d\n", solution.strStr("abbabaaaabbbaabaabaabbbaaabaaaaaabbbabbaabbabaabbabaaaaababbabbaaaaabbbbaaabbaaabbbbabbbbaaabbaaaaababbaababbabaaabaabbbbbbbaabaabaabbbbababbbababbaaababbbabaabbaaabbbba", "bbbbbbaa"));
    return 0;
}
