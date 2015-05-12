/*=============================================================================
#     FileName: 187-RepeatedDNASequences.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 17:48:44
#      Version: 0.0.1
#   LastChange: 2015-05-12 18:59:17
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <leetcode.h>
#include <unordered_set>

class Solution {
public:

    //253ms
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        int len = s.length();
        if (len < 10) {
            return result;
        }
        map<int, int> m;
        int key = 0;
        for (int i = 0; i < len; i ++) {
            key = ((key << 3) | (s[i] & 0x7)) & 0x3fffffff;
            if (i < 9) {
                continue;
            }
            if (m.find(key) == m.end()) {
                m[key] = 1;
            } else if (m.find(key) != m.end()) {
                if (m[key] == 1) {
                    result.push_back(s.substr(i - 9, 10));
                    m[key] = 2;
                }
            }
        }
        return result;
    }

};
