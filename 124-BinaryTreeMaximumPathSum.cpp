/*=============================================================================
#     FileName: 124-BinaryTreeMaximumPathSum.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-09 07:55:17
#      Version: 0.0.1
#   LastChange: 2015-05-09 08:03:35
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <algorithm>
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
    int max_path(TreeNode *root, int &result) {
        if (!root) {
            return 0;
        }
        int sum_left = max_path(root->left, result), sum_right = max_path(root->right, result);
        int sum = root->val;
        sum += max(0, sum_left);
        sum += max(0, sum_right);
        result = max(result, sum);
        return max(0, max(sum_left, sum_right)) + root->val;
    }
    //33ms
    int maxPathSum(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int result = INT_MIN;
        max_path(root, result);
        return result;
    }
};
