/*=============================================================================
#     FileName: 160-IntersectionOfTwoLinkedLists.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 11:44:16
#      Version: 0.0.1
#   LastChange: 2015-05-12 11:48:55
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

    //53ms
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return NULL;
        }
        int len1 = 0, len2 = 0;
        ListNode *tmp;
        tmp = headA;
        while (tmp) {
            tmp = tmp->next;
            len1 ++;
        }
        tmp = headB;
        while (tmp) {
            tmp = tmp->next;
            len2 ++;
        }
        
        if (len1 < len2) {
            for (int i = 0; i < len2 - len1; i ++) {
                headB = headB->next;
            }
        } else if (len1 >= len2) {
            for (int i = 0; i < len1 - len2; i ++) {
                headA = headA->next;
            }
        }
        while (headA && headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
