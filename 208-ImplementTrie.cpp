/*=============================================================================
#     FileName: 208-ImplementTrie.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-31 19:29:23
#      Version: 0.0.1
#   LastChange: 2015-05-31 19:29:23
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    map<char, TrieNode*> childMap;
    bool isWord; 
    TrieNode() {
        isWord = false;
    }
};

class Trie {
public:
    //144ms
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* node = root;
        for (auto c: s) {
            if (node->childMap.find(c) == node->childMap.end()) {
                TrieNode* child = new TrieNode();
                node->childMap[c] = child;
            }
            node = node->childMap[c];
        }
        node->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *node = root;
        for (auto c: key) {
            if (node->childMap.find(c) == node->childMap.end()) {
                return false;
            }
            node = node->childMap[c];
        }
        return node->isWord;
    }
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (auto c: prefix) {
            if (node->childMap.find(c) == node->childMap.end()) {
                return false;
            }
            node = node->childMap[c];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");


int main() {
    Trie trie;
    trie.insert("abc");
    cout << trie.search("abc") << endl;
    cout << trie.search("ab") << endl;
    trie.insert("ab");
    cout << trie.search("ab") << endl;
    trie.insert("ab");
    cout << trie.search("ab") << endl;

    return 0;
    //Volumesinsert("ab"),search("abc"),search("ab"),startsWith("abc"),startsWith("ab"),insert("ab"),search("abc"),startsWith("abc"),insert("abc"),search("abc"),startsWith("abc")
    //var
}
