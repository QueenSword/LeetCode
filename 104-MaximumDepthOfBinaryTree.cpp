/*=============================================================================
#     FileName: 104-MaximumDepthOfBinaryTree.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-05 10:16:18
#      Version: 0.0.1
#   LastChange: 2015-05-05 10:20:01
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
    //11ms
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
