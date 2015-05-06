/*=============================================================================
#     FileName: 102-BinaryTreeLevelOrderTraversal.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-05 09:03:54
#      Version: 0.0.1
#   LastChange: 2015-05-05 09:03:54
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    //14ms
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if (!root) {
            return result;
        }
        queue<TreeNode *> node_queue;
        node_queue.push(root);
        int count = 1;
        vector<int> ret;
        while (!node_queue.empty()) {
            TreeNode *node = node_queue.front();
            ret.push_back(node->val);
            if (node->left) {
                node_queue.push(node->left);
            }
            if (node->right) {
                node_queue.push(node->right);
            }
            node_queue.pop();
            count --;
            if (count == 0) {
                result.push_back(ret);
                ret.clear();
                if (node_queue.empty()) {
                    break;
                }
                count = node_queue.size();
            }
        }
        return result;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    Solution solution;
    vector<vector<int> > result = solution.levelOrder(root);
    for (int i = 0; i < result.size(); i ++) {
        for (int j = 0; j < result[i].size(); j ++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
