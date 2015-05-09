/*=============================================================================
#     FileName: 114-FlattenBinaryTreeToLinkedList.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-08 18:29:35
#      Version: 0.0.1
#   LastChange: 2015-05-08 18:36:53
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
    //10ms
    void flatten(TreeNode* root) {
        if (!root) {
            return ;
        }
        if (!(root->left)) {
            flatten(root->right);
            return ;
        }
        TreeNode *left = root->left, *right = root->right, *tail = left;
        while (tail->right) {
            tail = tail->right;
        }
        root->left = NULL;
        root->right = left;
        tail->right = right;
        flatten(root->right);
    }

};
