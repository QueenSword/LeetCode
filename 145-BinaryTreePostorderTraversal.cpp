/*=============================================================================
#     FileName: 145-BinaryTreePostorderTraversal.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-11 10:15:15
#      Version: 0.0.1
#   LastChange: 2015-05-11 10:18:35
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
        dfs(root->left, result);
        dfs(root->right, result);
        result.push_back(root->val);
    }
    //5ms
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }

};
