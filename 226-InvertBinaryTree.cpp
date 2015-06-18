/*=============================================================================
#     FileName: 226-InvertBinaryTree.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-06-18 15:58:27
#      Version: 0.0.1
#   LastChange: 2015-06-18 16:05:55
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //0ms
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode *node = root->left;
        root->left = root->right;
        root->right = node;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
