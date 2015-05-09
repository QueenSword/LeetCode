/*=============================================================================
#     FileName: 129-SumRootToLeafNumbers.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-09 17:42:58
#      Version: 0.0.1
#   LastChange: 2015-05-09 17:51:35
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
    
    void dfs(TreeNode *root, int val, int &sum) {
        val = val * 10 + root->val;
        if (!(root->left) && !(root->right)) {
            sum += val;
            return ;
        }
        if (root->left) {
            dfs(root->left, val, sum);
        }
        if (root->right) {
            dfs(root->right, val, sum);
        }
    }
    //5ms
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int sum = 0;
        dfs(root, 0, sum);
        return sum;

    }
};
