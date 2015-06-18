/*=============================================================================
#     FileName: 222-CountCompleteTreeNodes.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-06-18 22:25:16
#      History:
=============================================================================*/

#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //TLE
    /*int countNodes(TreeNode* root) {*/
        //if (root == NULL) {
            //return 0;
        //}
        //return 1 + countNodes(root->left) + countNodes(root->right);
    /*}*/
    
    //372ms
    int countNodes(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = 0, rightHeight = 0;
        for (TreeNode *p = root; p; p = p->left) {
            leftHeight ++;
        }
        for (TreeNode *p = root; p; p = p->right) {
            rightHeight ++;
        }
        if (leftHeight == rightHeight) {
            return pow(2, leftHeight) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
