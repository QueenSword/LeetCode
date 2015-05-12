/*=============================================================================
#     FileName: 141-LinkedListCycle.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-10 19:03:06
#      Version: 0.0.1
#   LastChange: 2015-05-10 19:08:20
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
    //14ms
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        ListNode *fast = head, *slow = head;
        while (fast && slow) {
            fast = fast->next;
            if (!fast) {
                return false;
            }
            fast = fast->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }

};
