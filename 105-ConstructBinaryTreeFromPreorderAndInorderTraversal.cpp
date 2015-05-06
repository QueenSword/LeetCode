/*=============================================================================
#     FileName: 105-ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-05 10:21:07
#      Version: 0.0.1
#   LastChange: 2015-05-05 12:14:02
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //57ms 
    TreeNode *build_tree(vector<int> &preorder, int low1, int high1, vector<int> &inorder, int low2, int high2) {
        if (low1 > high1) {
            return NULL;
        }
        if (low1 == high1) {
            return new TreeNode(preorder[low1]);
        }
        TreeNode *root = new TreeNode(preorder[low1]);
        int count = 0;
        while (inorder[low2 + count] != preorder[low1]) {
            count ++;
        }
        root->left = build_tree(preorder, low1 + 1, low1 + count, inorder, low2, low2 + count - 1);
        root->right = build_tree(preorder, low1 + count + 1, high1, inorder, low2 + count + 1, high2);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || !preorder.size()) {
            return NULL;
        }
        
        return build_tree(preorder, 0, (int)preorder.size() - 1, inorder, 0, (int)inorder.size() - 1);
    }
};
