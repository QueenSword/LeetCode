/*=============================================================================
#     FileName: 58-LengthOfLastWord.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-11 17:50:39
#      Version: 0.0.1
#   LastChange: 2015-04-11 17:50:39
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    //4ms
    int lengthOfLastWord(const char *s) {
        int len = strlen(s), pos1 = len - 1, pos2;
        if (len == 0) {
            return 0;
        }
        while (pos1 >= 0 && s[pos1] == ' ') {
            pos1 --;
        }
        pos2 = pos1;
        while (pos2 >= 0 && s[pos2] != ' ') {
            pos2 --;
        }
        return pos1 - pos2;
    }
};

int main() {
    char s[] = "Hello World";
    Solution solution;
    cout << solution.lengthOfLastWord(s) << endl;
    return 0;
}
