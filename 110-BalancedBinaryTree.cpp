/*=============================================================================
#     FileName: 110-BalancedBinaryTree.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-05 14:13:27
#      Version: 0.0.1
#   LastChange: 2015-05-05 14:13:27
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int depth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return 1 + max(max_depth(root->left), max_depth(root->right));
    }
    //18ms
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        if (isBalanced(root->left) && isBalanced(root->right)) {
            if (abs(depth(root->left) - depth(root->right)) < 2) {
                return true;
            }
        }
        return false;
    }
};
