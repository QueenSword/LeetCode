/*=============================================================================
#     FileName: 230-KthSmallestElementInABST.cpp
#         Desc: AC
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-07-29 19:00:23
#      History:
=============================================================================*/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        int totalNum(TreeNode* root) {
            if (!root) {
                return 0;
            }
            return 1 + totalNum(root->left) + totalNum(root->right);
        }
        int kthSmallest(TreeNode* root, int k) {
            int leftNum = totalNum(root->left);
            if (k == leftNum + 1) {
                return root->val;
            } else if (k < leftNum + 1) {
                return kthSmallest(root->left, k);
            }
            return kthSmallest(root->right, k - leftNum - 1);
        }

};

