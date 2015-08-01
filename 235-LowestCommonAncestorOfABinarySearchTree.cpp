/*=============================================================================
#     FileName: 235-LowestCommonAncestorOfABinarySearchTree.cpp
#         Desc: AC, 44ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-07-30 09:24:44
#      History:
=============================================================================*/

#include <leetcode.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            int rootVal = root->val, pVal = p->val, qVal = q->val;
            if (rootVal == pVal || rootVal == qVal) {
                return root;
            }
            if (pVal < rootVal && qVal < rootVal) {
                return lowestCommonAncestor(root->left, p, q);
            }
            if (pVal > rootVal && qVal > rootVal) {
                return lowestCommonAncestor(root->right, p, q);
            }
            return root;
        }
};

