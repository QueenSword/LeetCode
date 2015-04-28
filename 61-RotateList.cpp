/*=============================================================================
#     FileName: 61-RotateList.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-28 22:21:17
#      Version: 0.0.1
#   LastChange: 2015-04-28 22:21:17
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
    //13ms
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        int len = 0;
        ListNode *tail = head;
        while (tail != NULL) {
            tail = tail->next;
            len ++;
        }
        k = ((k % len) + len) % len;
        if (k == 0) {
            return head;
        }
        tail = head;
        for (int i = 0; i < len - k - 1; i ++) {
            tail = tail->next;
        }
        ListNode *node1 = tail->next, *node2 = node1;
        while (node2->next != NULL) {
            node2 = node2->next;
        }
        node2->next = head;
        tail->next = NULL;
        head = node1;
        return head;
    }
};

int main() {
    ListNode *node1 = new ListNode(1), *node2 = new ListNode(2), *node3 = new ListNode(3), *node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    Solution solution;
    node1 = solution.rotateRight(node1, 1);
    while (node1 != NULL) {
        printf("%d ", node1->val);
        node1 = node1->next;
    }
    printf("\n");
    return 0;
}
