/*=============================================================================
#     FileName: 21-MergeTwoSortedLists.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-06 13:37:15
#      Version: 0.0.1
#   LastChange: 2015-04-06 13:37:15
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

    //27ms
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        ListNode *head = NULL, *tail = NULL;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                if (head == NULL) {
                    head = new ListNode(l1->val);
                    tail = head;
                } else {
                    tail->next = new ListNode(l1->val);
                    tail = tail->next;
                }
                l1 = l1->next;
            } else {
                if (head == NULL) {
                    head = new ListNode(l2->val);
                    tail = head;
                } else {
                    tail->next = new ListNode(l2->val);
                    tail = tail->next;
                }
                l2 = l2->next;
            }
        }
        if (l1 == NULL) {
            l1 = l2;
        }
        while (l1 != NULL) {
            tail->next = new ListNode(l1->val);
            tail = tail->next;
            l1 = l1->next;
        }
        return head;
    }
};

int main() {
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(1);
    Solution solution;
    ListNode *l3 = solution.mergeTwoLists(l1, l2);
    while (l3 != NULL) {
        cout << l3->val << " ";
        l3 = l3->next;
    }
    cout << endl;

    return 0;
}
