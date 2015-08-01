/*=============================================================================
#     FileName: 126-WordLadderII.cpp
#         Desc: TLE
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-01 14:47:12
#      History:
=============================================================================*/

#include <leetcode.h>
#include <unordered_set>

class Solution {
    public:
        int ladderLength(string beginWord, string endWord, unordered_set<string> wordDict) {
            /*cout << beginWord << " " << endWord << " " << endl;*/
            //for (unordered_set<string>::iterator it = wordDict.begin(); it != wordDict.end(); it ++) {
                //cout << *it << " ";
            //}
            /*cout << endl;*/
            if (beginWord == endWord) {
                return 0;
            };
            queue<string> str_queue;
            str_queue.push(beginWord);
            int count = 1, step = 1;
            while (count) {
                string word = str_queue.front();
                str_queue.pop();
                for (int i = 0; i < (int)word.length(); i ++) {
                    string temp = word;
                    for (char j = 'a'; j <= 'z'; j ++) {
                        if (word[i] == j) {
                            continue;
                        }
                        temp[i] = j;
                        if (temp == endWord) {
                            return step + 1;
                        }
                        if (wordDict.find(temp) != wordDict.end()) {
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

        void print(vector<string> ret) {
            for (int i = 0; i < ret.size(); i ++) {
                cout << ret[i] << " ";
            }
            cout << endl;
        }
        void dfs(string end, unordered_set<string> &dict, vector<string> ret, vector<vector<string> > &result, int maxStep) {
            //print(ret);
            if ((int)ret.size() == maxStep) {
                return ;
            }
            int len = end.length();
            for (int i = 0; i < len; i ++) {
                for (char j = 'a'; j <= 'z'; j ++) {
                    string tmp = ret[ret.size() - 1];
                    //cout << "i = " << i << " ret size: " << ret.size() << " " << "ret end: " << ret[ret.size() - 1] << " " << *(ret.end() - 1) << endl;
                    if (tmp[i] == j) {
                        continue;
                    }
                    tmp[i] = j;
                    if (tmp == end) {
                        //cout << "find end " << tmp << endl;
                        ret.push_back(tmp);
                        result.push_back(ret);
                        return ;
                    }
                    if (dict.find(tmp) != dict.end()) {
                        //cout << "find tmp " << tmp << endl;
                        ret.push_back(tmp);
                        dict.erase(tmp);
                        dfs(end, dict, ret, result, maxStep);
                        dict.insert(tmp);
                        ret.erase(ret.end() - 1);
                    }
                }
            }
        }

        vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
            int minStep = ladderLength(start, end, dict);
            cout << "minStep: " << minStep << endl;
            vector<vector<string> > result;
            vector<string> ret;
            ret.push_back(start);
            dfs(end, dict, ret, result, minStep);
            return result;
        }
};

int main() {
    unordered_set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");

    Solution solution;
    vector<vector<string> > result = solution.findLadders("hit", "cog", dict);
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i ++) {
        cout << "result: " << endl;
        for (int j = 0; j < result[0].size(); j ++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    //cout << solution.ladderLength("hit", "cog", dict) << endl;
    return 0;
}

