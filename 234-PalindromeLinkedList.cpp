/*=============================================================================
#     FileName: 234-PalindromeLinkedList.cpp
#         Desc: AC, 28ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-07-30 08:54:05
#      History:
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

        ListNode* reverseList(ListNode* head) {
            if (!head || !head->next) {
                return head;
            }
            ListNode *prev = NULL, *current = head, *next = head->next;
            while (next) {
                current->next = prev;
                prev = current;
                current =next;
                next = next->next;
            }
            current->next = prev;
            return current;
        }

        bool isPalindrome(ListNode* head) {
            if (!head || !head->next) {
                return true;
            }
            ListNode *fast = head->next, *slow = head, *head1 = NULL;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            head1 = slow->next;
            slow->next = NULL;
            head1 = reverseList(head1);
            while (head1 && head) {
                if (head->val != head1->val) {
                    return false;
                }
                head = head->next;
                head1 = head1->next;
            }
            return true;
        }
};

int main() {
    ListNode *node1 = new ListNode(1), *node2 = new ListNode(0), *node3 = new ListNode(1);
    node1->next = node2;
    node2->next = node3;
    Solution solution;
    cout << solution.isPalindrome(node1) << endl;
    return 0;
}
