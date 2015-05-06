/*=============================================================================
#     FileName: 109-ConvertSortedListToBinarySearchTree.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-05 13:37:30
#      Version: 0.0.1
#   LastChange: 2015-05-05 13:53:57
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //29ms
    TreeNode *build_bst(ListNode *head, int len) {
        if (len <= 0 || !head) {
            return NULL;
        }
        if (len == 1) {
            return new TreeNode(head->val);
        }
        ListNode *node = head;
        for (int i = 0; i < len / 2; i ++) {
            node = node->next;
        }
        TreeNode *root = new TreeNode(node->val);
        root->left = build_bst(head, len / 2);
        root->right = build_bst(node->next, len - len / 2 - 1);
        return root;
    }

    TreeNode* sortedListToBST(ListNode *head) {
        if (!head) {
            return NULL;
        }
        int len = 0;
        ListNode *tail = head;
        while (tail) {
            tail = tail->next;
            len ++;
        }
        return build_bst(head, len);
    }
};

int main() {
    ListNode *head = new ListNode(0);
    Solution solution;
    TreeNode *root = solution.sortedListToBST(head);
    printf("%d\n", root->val);

    return 0;
}
