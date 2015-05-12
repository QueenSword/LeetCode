/*=============================================================================
#     FileName: 203-RemoveLinkedListElements.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 21:26:38
#      Version: 0.0.1
#   LastChange: 2015-05-12 21:26:38
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <leetcode.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //38ms
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return head;
        }
        while (head && head->val == val) {
            head = head->next;
        }
        if (!head || !(head->next)) {
            return head;
        }
        ListNode *tail = head;
        while (tail->next) {
            while (tail->next && tail->next->val != val) {
                tail = tail->next;
            }
            if (!(tail->next)) {
                return head;
            }
            tail->next = tail->next->next;
        }
        return head;
    }
};
