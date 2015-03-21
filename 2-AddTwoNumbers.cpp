/*=============================================================================
#     FileName: 2-AddTwoNumbers.cpp
#         Desc: :
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-03-21 15:52:09
#      Version: 0.0.1
#   LastChange: 2015-03-21 15:52:09
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
    // 59ms
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL, *tail = NULL;
        int c = 0;
        if (l1 == NULL || l2 == NULL) {
            return l1 == NULL ? l2 : l1;
        }

        while (l1 != NULL && l2 != NULL) {
            int sum = c + l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
            c = sum / 10;
            sum = sum % 10;
            if (head == NULL) {
                head = new ListNode(sum);
                tail = head;
            } else {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
        }
        if (l1 == NULL) {
            l1 = l2;
        }
        while (l1 != NULL) {
            int sum = c + l1->val;
            c = sum / 10;
            sum = sum % 10;
            tail->next = new ListNode(sum);
            tail = tail->next;
            l1 = l1->next;
        }
        if (c != 0) {
            tail->next = new ListNode(c);
            tail = tail->next;
            tail->next = NULL;
        }
        return head;
    }
};


int main() {
    ListNode *l1 = new ListNode(2), *l2 = new ListNode(5);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
    


}
