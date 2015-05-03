/*=============================================================================
#     FileName: 68-TextJustification.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-29 14:49:18
#      Version: 0.0.1
#   LastChange: 2015-04-29 22:09:10
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    //1ms
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        if (words.empty()) {
            return ret;
        }
        string tmp;
        int len = words.size(), start = 0, deta, sum;
        while (start < len) {
            deta = 1;
            sum = words[start].length();
            while (start + deta < len && (sum + 1 + (int)words[start + deta].length() <= maxWidth)) {
                sum = sum + 1 + (int)words[start + deta].length();
                deta ++;
            }
            sum = 0;
            tmp = words[start];
            if (deta == 1) {
                while ((int)tmp.length() != maxWidth) {
                    tmp += ' ';
                }                
            } else if (start + deta == len) {
                for (int i = start + 1; i < len; i ++) {
                    tmp = tmp + " " + words[i];
                }
                while ((int)tmp.length() != maxWidth) {
                    tmp += ' ';
                }
            } else {
                for (int i = start; i < start + deta; i ++) {
                    sum += words[i].length();
                }
                int space_num = (maxWidth - sum) / (deta - 1);
         
                string space_str = "";
                for (int i = 0; i < space_num; i ++) {
                    space_str += ' ';
                }
                for (int i = start + 1; i < start + 1 + maxWidth - sum - space_num * (deta - 1); i ++) {
                    tmp += space_str;
                    tmp += ' ';
                    tmp += words[i];
                }
                for (int i = start + 1 + maxWidth - sum - space_num * (deta - 1); i < start + deta; i ++) {
                    tmp += space_str;
                    tmp += words[i];
                }
            }
            ret.push_back(tmp);
            start = start + deta;
        }
        return ret;
    }
};

int main() {
    string strs[] = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> words;
    for (int i = 0; i < 7; i ++) {
        words.push_back(strs[i]);
    }
    Solution solution;
    vector<string> ret = solution.fullJustify(words, 16);
    for (int i = 0; i < (int)ret.size(); i ++) {
        printf("%s\n", ret[i].c_str());
    }
    return 0;
}
