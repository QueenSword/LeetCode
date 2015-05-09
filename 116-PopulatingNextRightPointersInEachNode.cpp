/*=============================================================================
#     FileName: 116-PopulatingNextRightPointersInEachNode.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-08 19:03:23
#      Version: 0.0.1
#   LastChange: 2015-05-08 19:10:35
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    //33ms
    void connect_node(TreeLinkNode *left, TreeLinkNode *right) {
        if (!left) {
            return ;
        }
        left->next = right;
        right->next = NULL;
        connect_node(left->left, left->right);
        connect_node(left->right, right->left);
        connect_node(right->left, right->right);
    }
    void connect(TreeLinkNode *root) {
        if (!root) {
            return ;
        }
        root->next = NULL;
        connect_node(root->left, root->right);
    }

};
