/*=============================================================================
#     FileName: 236-LowestCommonAncestorOfABinaryTree.cpp
#         Desc: AC, 24ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-07-30 09:38:09
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
        bool isInTree(TreeNode *root, TreeNode *p) {
            if (!root) {
                return false;
            }
            return (p == root) || isInTree(root->left, p) || isInTree(root->right, p);
        }
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if (!root) {
                return NULL;
            }
            if (root == p || root == q) {
                return root;
            }
            TreeNode *left = lowestCommonAncestor(root->left, p, q), *right = lowestCommonAncestor(root->right, p, q);
            if (left && right) {
                return root;
            }
            return left ? left : right;
        }
        TreeNode* lowestCommonAncestorII(TreeNode* root, TreeNode* p, TreeNode* q) {
            if (root == p || root == q) {
                return root;
            }
            bool pLeft = isInTree(root->left, p), qLeft = isInTree(root->left, q);
            cout << pLeft << " "<< qLeft << endl;
            if (pLeft && qLeft) {
                return lowestCommonAncestor(root->left, p, q);
            }
            if (!pLeft && !qLeft) {
                return lowestCommonAncestor(root->right, p, q);
            }
            return root;
        }
};

int main() {
    TreeNode *root = new TreeNode(1), *p = new TreeNode(2), *q = new TreeNode(3);
    root->left = p;
    root->right = q;
    Solution solution;
    cout << solution.lowestCommonAncestor(root, p, q)->val << endl;
    return 0;
    
}
