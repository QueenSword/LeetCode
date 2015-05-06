/*=============================================================================
#     FileName: 107-BinaryTreeLevelOrderTraversalII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-05 12:34:38
#      Version: 0.0.1
#   LastChange: 2015-05-05 12:34:38
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

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
    //11ms
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        if (!root) {
            return result;
        }
        queue<TreeNode *> node_queue;
        vector<int> ret;
        int count = 1;
        node_queue.push(root);
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
            ret.push_back(node->val);
            if (count == 0) {
                result.push_back(ret);
                ret.clear();
                if (!node_queue.empty()) {
                    count = node_queue.size();
                }
            }
        }
        int i = 0, j = result.size() - 1;
        while (i < j) {
            swap(result[i ++], result[j --]);
        }
        return result;
    }
};
