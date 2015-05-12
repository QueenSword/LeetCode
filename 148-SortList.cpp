/*=============================================================================
#     FileName: 148-SortList.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 09:07:24
#      Version: 0.0.1
#   LastChange: 2015-05-12 09:25:10
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include "leetcode.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode * merge(ListNode *node1, ListNode *node2) {
        if (!node2) {
            return node1;
        }
        ListNode *head = NULL, *tail = NULL;
        while (node1 && node2) {
            if (head == NULL) {
                if (node1->val < node2->val) {
                    head = node1;
                    node1 = node1->next;
                } else {
                    head = node2;
                    node2 = node2->next;
                }
                tail = head;
            } else {
                if (node1->val < node2->val) {
                    tail->next = node1;
                    node1 = node1->next;
                } else {
                    tail->next = node2;
                    node2 = node2->next;
                }
                tail = tail->next;
            }
        }
        while (node1) {
            tail->next = node1;
            tail = tail->next;
            node1 = node1->next;
        }
        while (node2) {
            tail->next = node2;
            tail = tail->next;
            node2 = node2->next;
        }
        return head;
    }

    //64ms
    ListNode *sortList(ListNode *head) {
        if (!(head) || !(head->next)) {
            return head;
        }
        int len = 0;
        ListNode *tail = head;
        while (tail) {
            tail = tail->next;
            len ++;
        }
        tail = head;
        for (int i = 0; i < (len - 1) / 2; i ++) {
            tail = tail->next;
        }
        ListNode *tmp = sortList(tail->next);
        tail->next = NULL;
        head = sortList(head);
        tail = tmp;
        head = merge(head, tail);
        return head;
    }
};
