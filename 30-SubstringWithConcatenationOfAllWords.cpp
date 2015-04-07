/*=============================================================================
#     FileName: 30-SubstringWithConcatenationOfAllWords.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-07 10:38:56
#      Version: 0.0.1
#   LastChange: 2015-04-07 10:38:56
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    //725ms
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int > result;
        if (L.empty()) {
            return result;
        }
        int wordLen = L[0].length(), wordNum = L.size();
        if (S.length() < wordLen * wordNum) {
            return result;
        }
        map<string, int> wordMap;
        for (int i = 0; i < wordNum; i ++) {
            wordMap[L[i]] ++;
        }
        for (int i = 0; i < S.length() - wordNum * wordLen + 1; i ++) {
            int count = 0;
            map<string, int> m;
            for (int j = 0; j < wordNum; j ++) {
                string s = S.substr(i + j * wordLen, wordLen);
                if (wordMap.find(s) == wordMap.end()) {
                    break;
                } else {
                    m[s] ++;
                }
                if (m[s] > wordMap[s]) {
                    break;
                }
                count ++;
            }
            if (count == wordNum) {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main() {
    vector<string> vec;
    vec.push_back("foo");
    vec.push_back("bar");
    Solution solution;
    vector<int> result = solution.findSubstring("barfoothefoobarman", vec);
    cout <<  "size: " << result.size() << endl;
    for (int i = 0; i < result.size(); i ++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
