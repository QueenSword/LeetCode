/*=============================================================================
#     FileName: 173-BinarySearchTreeIterator.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-12 16:26:58
#      Version: 0.0.1
#   LastChange: 2015-05-12 16:44:11
#      History:
#               0.0.1 | qsword | init
=============================================================================*/

#include <leetcode.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode *> node_stack;
public:
    //30ms 
    void init(TreeNode *root) {
        if (!root) {
            return ;
        }
        init(root->right);
        node_stack.push(root);
        init(root->left);
    }
    
    BSTIterator(TreeNode *root) {        
        init(root); 
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !(node_stack.empty());
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = node_stack.top();
        node_stack.pop();
        return node->val;
    }
};



/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
