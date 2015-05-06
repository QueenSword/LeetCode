/*=============================================================================
#     FileName: 106-ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-05 10:21:07
#      Version: 0.0.1
#   LastChange: 2015-05-05 12:33:17
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
    //50ms
    TreeNode *build_tree(vector<int> &inorder, int low1, int high1, vector<int> &postorder, int low2, int high2) {
        if (low1 > high1) {
            return NULL;
        }
        if (low1 == high1) {
            return new TreeNode(inorder[low1]);
        }
        TreeNode *root = new TreeNode(postorder[high2]);
        int count = 0;
        while (inorder[low1 + count] != postorder[high2]) {
            count ++;
        }
        root->left = build_tree(inorder, low1, low1 + count - 1, postorder, low2, low2 + count - 1);
        root->right = build_tree(inorder, low1 + count + 1, high1, postorder, low2 + count, high2 - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || !inorder.size()) {
            return NULL;
        }
        
        return build_tree(inorder, 0, (int)inorder.size() - 1, postorder, 0, (int)postorder.size() - 1);
    }
};
