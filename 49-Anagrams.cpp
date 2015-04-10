/*=============================================================================
#     FileName: 49-Anagrams.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-10 20:37:15
#      Version: 0.0.1
#   LastChange: 2015-04-10 20:37:15
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    //76ms
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        if (strs.empty()) {
            return result;
        }

        map<string, int> anagram;
        for (int i = 0; i < strs.size(); i ++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (anagram.find(s) == anagram.end()) {
                anagram[s] = i;
            } else {
                if (anagram[s] >= 0) {
                    result.push_back(strs[anagram[s]]);
                    anagram[s] = -1;
                }
                result.push_back(strs[i]);
            }
        }
        return result;
    }
};
