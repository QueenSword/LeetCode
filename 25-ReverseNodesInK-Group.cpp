/*=============================================================================
#     FileName: 25-ReverseNodesInK-Group.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-06 21:57:02
#      Version: 0.0.1
#   LastChange: 2015-04-06 23:04:16
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
    ListNode *reverseList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head; 
        }
        ListNode *prevNode = NULL, *listNode = head, *nextNode = head->next;
        while (nextNode != NULL) {
            listNode->next = prevNode;
            prevNode = listNode;
            listNode = nextNode;
            nextNode = nextNode->next;
        }
        listNode->next = prevNode;
        return listNode;
    }
    //40ms
    ListNode *reverseKGroup(ListNode *head, int k) { 
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *superHead = new ListNode(0), *prevTail = superHead, *tmpHead = head, *tmpTail = head;
        while (tmpHead != NULL) {
            for (int i = 0; i < k - 1; i ++) {
                if (tmpTail->next != NULL) {
                    tmpTail = tmpTail->next;
                } else {
                    prevTail->next = tmpHead;
                    return superHead->next;
                }
            }
            ListNode *tail = tmpTail;
            tmpTail = tmpTail->next;
            tail->next = NULL;
            tmpHead = reverseList(tmpHead);
            prevTail->next = tmpHead;
            while (prevTail->next != NULL) {
                prevTail = prevTail->next;
            }
            tmpHead = tmpTail;   
        }
        
        return superHead->next;

    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    Solution solution;
    head = solution.reverseKGroup(head, 2);
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;    
}
