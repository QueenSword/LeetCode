/*=============================================================================
#     FileName: 19-RemoveNthNodeFromEndOfList.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-06 11:36:19
#      Version: 0.0.1
#   LastChange: 2015-04-06 11:36:19
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    //9ms
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *node = head;
        int length = 0;
        while (node != NULL) {
            node = node->next;
            length ++;
        }
        if (length < n) {
            return head;
        }
        if (length == n) {
            node = head->next;
            head->next = NULL;
            return node;
        }
        node = head;
        for (int i = 0; i < length - n - 1; i ++) {
            node = node->next;
        }
        node->next = node->next->next;
        return head;
    }
};

int main() {

    return 0;
}
