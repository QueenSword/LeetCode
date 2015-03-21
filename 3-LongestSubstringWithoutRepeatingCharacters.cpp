/*=============================================================================
#     FileName: 3-LongestSubstringWithoutRepeatingCharacters.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-03-21 15:53:33
#      Version: 0.0.1
#   LastChange: 2015-03-21 15:53:33
#      History:
#               0.0.1 | qsword | init
=============================================================================*/


#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    //132ms
    /*int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        map<char, int>::iterator it;
        int len = s.length(), curMax = 0, globalMax = 0, start = 0, end = 0;
        while (start < len) {
            printf("start: %d\n", start);
            while (end < len) {
                printf("end: %d\n", end);
                it = m.find(s[end]);
                if (it == m.end()) {
                    m.insert(pair<char, int>(s[end], end));
                    curMax ++;
                    end ++;
                    if (end == len) {
                        start = len;
                        globalMax = max(globalMax, curMax);
                        break;
                    }
                } else {
                    globalMax = max(globalMax, curMax);
                    int prevPos = it->second;
                    for (int i = start; i <= prevPos; i ++) {
                        m.erase(s[i]);
                    }
                    curMax = end - prevPos - 1;
                    start = prevPos + 1;
                    break;
                }
            }
        }
        return globalMax;
    }*/

    //20ms
    int lengthOfLongestSubstring(string s) {
        vector<int> hasChar(128, -1);
        int len = s.length(), curMax = 0, globalMax = 0, start = 0, end = 0;
        while (start < len) {
            while (end < len) {
                if (hasChar[s[end] - '\0'] == -1) {
                    hasChar[s[end] - '\0'] = end;
                    curMax ++;
                    end ++;
                    if (end == len) {
                        start = len;
                        globalMax = max(globalMax, curMax);
                        break;
                    }
                } else {
                    globalMax = max(globalMax, curMax);
                    int prevPos = hasChar[s[end] - '\0'];
                    for (int i = start; i <= prevPos; i ++) {
                        hasChar[s[i] - '\0'] = -1;
                    }
                    curMax = end - prevPos - 1;
                    start = prevPos + 1;
                    break;
                }
            }
        }
        return globalMax;
    }

};

int main() {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("eee") << endl;
    cout << solution.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << solution.lengthOfLongestSubstring("") << endl;
    cout << solution.lengthOfLongestSubstring("dvdf") << endl;
    return 0;
}
