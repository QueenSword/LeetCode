/*=============================================================================
#     FileName: 24-SwapNodesInPairs.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-06 21:57:02
#      Version: 0.0.1
#   LastChange: 2015-04-06 21:57:02
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

    //4ms
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *superHead = new ListNode(0), *prevNode = superHead, *listNode = head, *nextNode = head->next;
        superHead->next = listNode;
        while (listNode != NULL && nextNode!= NULL) {
            listNode->next = nextNode->next;
            nextNode->next = listNode;
            prevNode->next = nextNode;
            if (listNode->next == NULL || listNode->next->next == NULL) {
                break;
            }
            prevNode = listNode;
            listNode = listNode->next;
            nextNode = listNode->next;
        }
        return superHead->next;

    }
};

int main() {

    return 0;    
}
