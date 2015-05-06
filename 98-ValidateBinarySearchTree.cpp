/*=============================================================================
#     FileName: 98-ValidateBinarySearchTree.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-04 21:28:08
#      Version: 0.0.1
#   LastChange: 2015-05-05 08:52:00
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <limits.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //16ms 
    bool is_valid(TreeNode *root, long long int min, long long int max) {
        if (!root) {
            return true;
        }
        if (root->val <= min || root->val >= max) {
            return false;
        }
        return is_valid(root->left, min, root->val) && is_valid(root->right, root->val, max);
    }
    
    bool isValidBST(TreeNode* root) {
        long int min = INT_MIN, max = INT_MAX;
        return is_valid(root, min - 1, max + 1);
    }
};
