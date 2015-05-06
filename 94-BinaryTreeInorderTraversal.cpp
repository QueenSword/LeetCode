/*=============================================================================
#     FileName: 94-BinaryTreeInorderTraversal.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-04 19:58:49
#      Version: 0.0.1
#   LastChange: 2015-05-04 20:06:11
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <stdio.h>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<int> result;
public:

    //4ms
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) {
            return result;
        }
        inorderTraversal(root->left);
        result.push_back(root->val);
        inorderTraversal(root->right);
        return result;
    }
};
