/*=============================================================================
#     FileName: 92-ReverseLinkedListII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-03 19:50:47
#      Version: 0.0.1
#   LastChange: 2015-05-03 19:50:47
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (!head || !(head->next)) {
            return head;
        }
        ListNode *prev = NULL, *list = head, *next = head->next;
        while (next != NULL) {
            list->next = prev;
            prev = list;
            list = next;
            next = next->next;
        }
        list->next = prev;
        prev = list;
        while (prev != NULL) {
            printf("%d ", prev->val);
            prev = prev->next;
        }
        return list;
    }
    
    //6ms
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *head1 = head, *tail1 = head, *tail2;
        for (int i = 0; i < m - 2; i ++) {
            head1 = head1->next;
        }
        for (int i = 0; i < n - 1; i ++) {
            tail1 = tail1->next;
        }
        tail2 = tail1->next;
        tail1->next = NULL;
        if (m == 1) {
            head1 = reverseList(head);
            tail1 = head1;
            while (tail1->next != NULL) {
                tail1 = tail1->next;
            }
            tail1->next = tail2;
            return head1;
        }
        head1->next = reverseList(head1->next);
        tail1 = head1;
        while (tail1->next != NULL) {
            tail1 = tail1->next;
        }
        tail1->next = tail2;
        return head;
    }

};

int main() {
    ListNode *node1 = new ListNode(1), *node2 = new ListNode(2), *node3 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    Solution solution;
    node1 = solution.reverseList(node2);
    while (node1 != NULL) {
        printf("%d ", node1->val);
        node1 = node1->next;
    }
    printf("\n");
    return 0;
}
