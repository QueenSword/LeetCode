/*=============================================================================
#     FileName: 143-ReorderList.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-11 08:59:47
#      Version: 0.0.1
#   LastChange: 2015-05-11 10:02:09
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
    
    ListNode *reverse_list(ListNode *head) {
        if (!head || (!head->next)) {
            return head;
        }
        ListNode *prev = NULL, *list = head, *next = head->next;
        while (next) {
            list->next = prev;
            prev = list;
            list = next;
            next = next->next;
        }
        list->next = prev;
        return list;
    }
    //101ms
    void reorderList(ListNode* head) {
        if (!head || !(head->next)) {
            return ;
        }
        int len = 0;
        ListNode *head1 = head, *head2, *tail = head;
        while (head1) {
            head1 = head1->next;
            len ++;
        }
        head1 = head;
        for (int i = 0; i < (len - 1)/ 2; i ++) {
            head1 = head1->next;
        }
        head2 = head1->next;
        head1->next = NULL;
        head2 = reverse_list(head2);
        head1 = head;
        
        while (head1 && head2) {
            head1 = head1->next;
            tail->next = head2;
            head2 = head2->next;
            tail = tail->next;
            tail->next = head1;
            tail = tail->next;
        }
        
        return ; 
    }
};

int main() {
    ListNode *node1 = new ListNode(1), *node2 = new ListNode(2), *node3 = new ListNode(3), *node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    Solution solution;
    solution.reorderList(node1);
    while (node1) {
        printf("%d ", node1->val);
        node1 = node1->next;
    }
}
