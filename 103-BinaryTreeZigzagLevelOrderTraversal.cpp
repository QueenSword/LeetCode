/*=============================================================================
#     FileName: 103-BinaryTreeZigzagLevelOrderTraversal.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-05 09:43:38
#      Version: 0.0.1
#   LastChange: 2015-05-05 09:43:38
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
    //6ms
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if (!root) {
            return result;
        }
        vector<int> ret;
        vector<TreeNode *> node_vec;
        node_vec.push_back(root);
        int start = 0, count = node_vec.size();
        bool order = true;
        while (count) {
            ret.clear();
            if (order) {
                for (int i = start; i < start +  count; i ++) {
                    ret.push_back(node_vec[i]->val);
                }
            } else {
                for (int i = start + count - 1; i >= start; i --) {
                    ret.push_back(node_vec[i]->val);
                    
                }
            }
            for (int i = start; i < start + count; i ++) {
                TreeNode *node = node_vec[i];
                if (node->left != NULL) {
                    node_vec.push_back(node->left);
                }
                if (node->right != NULL) {
                    node_vec.push_back(node->right);
                }
            }
            result.push_back(ret);
            start += count;
            count = node_vec.size() - start;
            order = !order;
        }
        return result;
    }
};
