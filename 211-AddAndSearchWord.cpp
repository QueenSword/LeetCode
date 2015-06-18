/*=============================================================================
#     FileName: 211-AddAndSearchWord.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-06-18 10:33:06
#      Version: 0.0.1
#   LastChange: 2015-06-18 10:48:13
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <iostream>
#include <string.h>
#include <map>

using namespace std;

struct TrieNode {
    bool isWord;
    map<char, TrieNode*> childMap;

    TrieNode() {
        isWord = false;
    }
};

class WordDictionary {
private:
    TrieNode *root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    //252ms
    void addWord(string word) {
        TrieNode *node = root;
        for (auto c: word) {
            if (node->childMap.find(c) == node->childMap.end()) {
                node->childMap[c] = new TrieNode();
            }
            node = node->childMap[c];
        }
        node->isWord = true;
    }
    
    bool dfs(TrieNode *node, string word) {
        if (word == "") {
            return node->isWord;
        }
        char c = word[0];
        word = word.substr(1, word.length() - 1);
        if (c == '.') {
            map<char, TrieNode*>::iterator it;
            for (it = node->childMap.begin(); it != node->childMap.end(); it ++) {
                if (dfs(it->second, word)) {
                    return true;
                }
            }
            return false;
        }
        if (node->childMap.find(c) == node->childMap.end()) {
            return false;
        }
        return dfs(node->childMap[c], word);
    }

    bool search(string word) {
        return dfs(root, word);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
