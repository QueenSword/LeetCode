/*=============================================================================
#     FileName: 206-ReverseLinkedList.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 20:45:32
#      Version: 0.0.1
#   LastChange: 2015-05-12 20:45:32
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
    //12ms
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head->next)) {
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
};
