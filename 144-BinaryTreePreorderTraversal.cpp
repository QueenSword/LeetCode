/*=============================================================================
#     FileName: 144-BinaryTreePreorderTraversal.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-11 10:05:24
#      Version: 0.0.1
#   LastChange: 2015-05-11 10:14:02
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include "leetcode.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    
    void dfs(TreeNode *root, vector<int> &result) {
        if (!root) {
            return ;
        }
        result.push_back(root->val);
        dfs(root->left, result);
        dfs(root->right, result);
    }
    //3ms
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }

};
