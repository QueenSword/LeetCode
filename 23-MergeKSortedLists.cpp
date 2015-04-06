/*=============================================================================
#     FileName: 23-MergeKSortedLists.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-04-06 14:26:52
#      Version: 0.0.1
#   LastChange: 2015-04-06 14:26:52
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    /*friend bool operator< (ListNode n1, ListNode n2) {
        return n1.val < n2.val;
    }*/
};

bool cmp(ListNode *node1, ListNode *node2) {
    return node1->val > node2->val;
}

class Solution {
public:

    //23ms
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = NULL, *tail = NULL;
        if (lists.empty()) {
            return head;
        }
        for (int i = 0; i < lists.size(); i ++) {
            if (lists[i] == NULL) {
                lists[i] = new ListNode(INT_MAX);
                continue;
            }
            ListNode *node = lists[i];
            while (node->next != NULL) {
                node = node->next;
            }
            node->next = new ListNode(INT_MAX);
        }
        
        make_heap(lists.begin(), lists.end(), cmp);
        
        while (lists[0]->val != INT_MAX) {
            if (head == NULL) {
                head = new ListNode(lists[0]->val);
                tail = head;
            } else {
                tail->next = new ListNode(lists[0]->val);
                tail = tail->next;
                
            }
            ListNode *node = lists[0];
            pop_heap(lists.begin(), lists.end(), cmp);
            lists.pop_back();
            lists.push_back(node->next);
            push_heap(lists.begin(), lists.end(), cmp);
        }


        return head;
    }
};


int main() {

    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(0);
    vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    Solution solution;
    ListNode *list = solution.mergeKLists(lists);
    while (list != NULL) {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
    return 0;
}
