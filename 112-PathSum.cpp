#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    //18ms
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) {
            return false;
        }
        sum -= root->val;
        if (root->left && hasPathSum(root->left, sum)) {
            return true;
        }
        if (root->right && hasPathSum(root->right, sum)) {
            return true;
        }
        if (!(root->left) && !(root->right)) {
            return sum == 0 ? true : false;
        }
        return false;

    }

};
