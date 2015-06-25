/*=============================================================================
#     FileName: 99-RecoverBinarySearchTree.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-06-19 14:18:29
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
    TreeNode *mistake1, *mistake2;
    int count;
    void travelMidOrder(TreeNode * root) {
        if(root == NULL) {
            return ;
        }
        if (root->left) {
            if (root->val < root->left->val) {
                
            }
        }
    }


    void recoverTree(TreeNode* root) {
        
    }
};
