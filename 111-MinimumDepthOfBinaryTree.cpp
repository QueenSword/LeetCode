/*=============================================================================
#     FileName: 111-MinimumDepthOfBinaryTree.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-05 14:25:52
#      Version: 0.0.1
#   LastChange: 2015-05-05 14:25:52
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
    //13ms
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        if (root->left && root->right) {
            return 1 + min(minDepth(root->left), minDepth(root->right));
        }
        return 1 + max(minDepth(root->left), minDepth(root->right));
    }
};
