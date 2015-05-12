/*=============================================================================
#     FileName: 147-InsertionSortList.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-11 10:19:58
#      Version: 0.0.1
#   LastChange: 2015-05-12 09:06:28
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
    //94ms
    ListNode *insertionSortList(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }
        ListNode *sorted = head, *tmp;
        while (sorted->next) {
            if (sorted->next->val < head->val) {
                tmp = sorted->next;
                sorted->next = tmp->next;
                tmp->next = head;
                head = tmp;
            } else {
                tmp = head;
                while (tmp != sorted &&  tmp->next->val <= sorted->next->val) {
                    tmp = tmp->next;
                }
                if (tmp == sorted) {
                    sorted = sorted->next;
                } else {
                    ListNode *unsorted = sorted->next;
                    sorted->next = unsorted->next;
                    unsorted->next = tmp->next;
                    tmp->next = unsorted;
                }
            }
        }
        return head;
        
    }

};
