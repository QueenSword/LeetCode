/*=============================================================================
#     FileName: 95-UniqueBinarySearchTreesII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-04 20:38:04
#      Version: 0.0.1
#   LastChange: 2015-05-04 21:04:16
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
private: 
    vector<TreeNode*> result;
public:
    //27ms
    vector<TreeNode *> generate_node(int start, int end) {
        vector<TreeNode *> result;
        if (start > end) {
            result.push_back(NULL);
            return result;
        }
        if (start == end) {
            result.push_back(new TreeNode(start));
            return result;
        }
        for (int i = start; i <= end; i ++) {
            vector<TreeNode *> left_tree = generate_node(start, i - 1);
            vector<TreeNode *> right_tree = generate_node(i + 1, end);
            for (int j = 0; j < left_tree.size(); j ++) {
                for (int k = 0; k < right_tree.size(); k ++) {
                    TreeNode *node = new TreeNode(i);
                    node->left = left_tree[j];
                    node->right = right_tree[k];
                    result.push_back(node);
                }
            }
        }
        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generate_node(1, n);
    }
};
