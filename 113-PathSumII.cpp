/*=============================================================================
#     FileName: 113-PathSumII.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-06 10:51:49
#      Version: 0.0.1
#   LastChange: 2015-05-06 10:58:52
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
    vector<vector<int> > result;
public:
    
    void dfs(vector<int> ret, TreeNode *root, int sum) {
        if (!root) {
            return ;
        }
        sum -= root->val;
        ret.push_back(root->val);
        if (!(root->left) && !(root->right)) {
            if (sum == 0) {
                result.push_back(ret);
            }
            return ;
        }
        if (root->left) {
            dfs(ret, root->left, sum);
        }
        if (root->right) {
            dfs(ret, root->right, sum);
        }
    }
    //49ms
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        if (!root) {
            return result;
        }
        vector<int> ret;
        dfs(ret, root, sum);
        return result;
    }

};

