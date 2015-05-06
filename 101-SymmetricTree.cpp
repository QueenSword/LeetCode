/*=============================================================================
#     FileName: 101-SymmetricTree.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-05 08:57:53
#      Version: 0.0.1
#   LastChange: 2015-05-05 08:57:53
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
    //15ms
    bool is_symmetric_tree(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2) {
            return true;
        }
        if ((!root1 && root2) || (root1 && !root2) || root1->val != root2->val) {
            return false;
        }
        return is_symmetric_tree(root1->left, root2->right) && is_symmetric_tree(root1->right, root2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return is_symmetric_tree(root->left, root->right);
    }
};
