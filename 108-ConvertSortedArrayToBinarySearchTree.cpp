/*=============================================================================
#     FileName: 108-ConvertSortedArrayToBinarySearchTree.cpp
#         Desc: 
#       Author: qsword
#        Email: huangjian1993@gmail.com
#     HomePage: 
#      Created: 2015-05-05 13:37:30
#      Version: 0.0.1
#   LastChange: 2015-05-05 13:37:30
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
public:
    //19ms
    TreeNode *build_bst(vector<int> &nums, int low, int high) {
        if (low > high) {
            return NULL;
        }
        if (low == high) {
            return new TreeNode(nums[low]);
        }
        int mid = (high + low + 1) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = build_bst(nums, low, mid - 1);
        root->right = build_bst(nums, mid + 1, high);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return NULL;
        }
        return build_bst(nums, 0, nums.size() - 1);
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    Solution solution;
    TreeNode *root = solution.sortedArrayToBST(nums);
    printf("%d \n", root->val);

    return 0;
}
