/*=============================================================================
#     FileName: 199-BinaryTreeRightSideView.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 19:03:06
#      Version: 0.0.1
#   LastChange: 2015-05-12 19:07:00
#      History:
#               0.0.1 | qsword | init
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

    //7ms
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) {
            return result;
        }
        queue<TreeNode *> node_queue;
        node_queue.push(root);
        int count = 1;
        while (!node_queue.empty()) {
            TreeNode *node = node_queue.front();
            node_queue.pop();
            if (node->left) {
                node_queue.push(node->left);
            }
            if (node->right) {
                node_queue.push(node->right);
            }
            count --;
            if (!count) {
                result.push_back(node->val);
                count = node_queue.size();
            }
        }
        return result;
    }
};
