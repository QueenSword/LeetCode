/*=============================================================================
#     FileName: 142-LinkedListCycleII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-10 19:09:18
#      Version: 0.0.1
#   LastChange: 2015-05-10 19:15:32
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
    ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return NULL;
        }
        ListNode *fast = head, *slow = head;
        while (fast && slow) {
            fast = fast->next;
            if (!fast) {
                return NULL;
            }
            fast = fast->next;
            slow = slow->next;
            if (slow == fast) {
                fast = head;
                while (slow != fast) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
