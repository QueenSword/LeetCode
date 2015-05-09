/*=============================================================================
#     FileName: 117-PopulatingNextRightPointersInEachNodeII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-08 19:12:05
#      Version: 0.0.1
#   LastChange: 2015-05-08 19:12:05
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <queue>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    //40ms
    void connect(TreeLinkNode *root) {
        if (!root) {
            return ;
        }
        queue<TreeLinkNode *> node_queue;
        node_queue.push(root);
        int count = 1;
        while (true) {
            TreeLinkNode *node = node_queue.front();
            node_queue.pop();
            if (count == 1) {
                node->next = NULL;
                
            } else {
                node->next = node_queue.front();
            }
            if (node->left) {
                node_queue.push(node->left);
            }
            if (node->right) {
                node_queue.push(node->right);
            }
            if (node_queue.empty()) {
                break;
            }
            count --;
            if (!count) {
                count = node_queue.size();
            }
        }
    }

};
