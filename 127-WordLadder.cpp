/*=============================================================================
#     FileName: 127-WordLadder.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-09 09:48:26
#      Version: 0.0.1
#   LastChange: 2015-05-09 13:54:56
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    //292ms
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if (beginWord == endWord) {
            return 0;
        };
        queue<string> str_queue;
        str_queue.push(beginWord);
        int count = 1, step = 1;
        while (count) {
            string word = str_queue.front();
            str_queue.pop();
            for (int i = 0; i < word.length(); i ++) {
                string temp = word;
                for (char j = 'a'; j <= 'z'; j ++) {
                    if (word[i] == j) {
                        continue;
                    }
                    temp[i] = j;
                    if (wordDict.find(temp) != wordDict.end()) {
                        if (temp == endWord) {
                            return step + 1;
                        }
                        str_queue.push(temp);
                        wordDict.erase(temp);
                    }
                }
            }
            count --;
            if (count == 0) {
                step ++;
                count = str_queue.size();
            }
        }
        return 0;
    }
};

int main() {
    string strs[] = {"hot","dot","dog","lot","log"};
    unordered_set<string> wordDict;
    for (int i = 0; i < 3; i ++) {
        wordDict.insert(strs[i]);
    }

    Solution solution;
    printf("%d\n", solution.ladderLength("hit", "cog", wordDict));

}
