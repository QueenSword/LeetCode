/*=============================================================================
#     FileName: 86-PartitionList.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-30 13:26:30
#      Version: 0.0.1
#   LastChange: 2015-04-30 13:26:30
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>
#include <limits.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    
    //12ms
    ListNode* partition(ListNode* head, int x) {
        if (!head || !(head->next)) {
            return head;
        }
        vector<ListNode *> vec;
        ListNode *super_head = new ListNode(INT_MIN), *prev = super_head, *next = head;
        super_head->next = head;
        while (next != NULL) {
            if (next->val < x) {
                next = next->next;
                prev = prev->next;
            } else {
                vec.push_back(next);
                prev->next = next->next;
                next->next = NULL;
                next = prev->next;
            }
        }
        for (int i = 0; i < (int)vec.size(); i ++) {
            prev->next = vec[i];
            prev = prev->next;
        }
        return super_head->next;
    }
};
