/*=============================================================================
#     FileName: 237-DeleteNodeInALinkedList.cpp
#         Desc: AC, 16ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-07-30 12:02:20
#      History:
=============================================================================*/

#include <leetcode.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        void deleteNode(ListNode* node) {
            if (!node->next) {
                node = NULL;
                return ;
            }
            node->val = node->next->val;
            node->next = node->next->next;
        }

};

