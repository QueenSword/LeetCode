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

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    vector<TrieNode *> childs;
    bool isWord; 
    TrieNode() {
        for (int i = 0; i < 26; i ++) {
            childs.push_back(NULL);
        }
        isWord = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* node = root;
        int len = s.length();
        for (int i = 0; i < len; i ++) {
            TrieNode *child = node->childs[s[i] - 'a'];
            if (!child) {
                child = new TrieNode();
                node->childs[s[i] - 'a'] = child;
            }
            node = child;
        }
        node->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *node = root;
        int len = key.length();
        for (int i = 0; i < len; i ++) {
            TrieNode *child = node->childs[key[i] - 'a'];
            if (!child) {
                return false;
            }
            node = child;
        }
        return node->isWord;
    }
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *node = root;
        int len = prefix.length();
        for (int i = 0; i < len; i ++) {
            TrieNode *child = node->childs[prefix[i] - 'a'];
            if (!child) {
                return false;
            }
            node = child;
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
