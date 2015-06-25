/*=============================================================================
#     FileName: 220-ContainsDuplicateIII.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-06-20 11:58:10
#      History:
=============================================================================*/

#include <leetcode.h>

struct TreeNode {
    TreeNode *left, *right;
    int value, index;
    TreeNode(int val, int id) {
        left = right = NULL;
        value = val;
        index = id;
    }
};

class Solution {
public:
    //16ms
    bool insertNode(TreeNode **root, int value, int index, int k, int t) {
        if ((*root) == NULL) {
            *root = new TreeNode(value, index);
            return true;
        }
        if (value == (*root)->value) {
            if (abs((*root)->index - index) <= k) {
                return false;
            } else {
                (*root)->index = index;
                return true;
            }
        } else if (labs(long(value) - long((*root)->value)) <= t && abs((*root)->index - index) <= k) {
                return false;
                
        } else {
            if (value < (*root)->value) {
                if (!(*root)->left) {
                    (*root)->left = new TreeNode(value, index);
                    return true;
                } else {
                    return insertNode(&(*root)->left, value, index, k, t);
                }
            } else {
                if (!(*root)->right) {
                    (*root)->right = new TreeNode(value, index);
                    return true;
                } else {
                    return insertNode(&(*root)->right, value, index, k, t);
                }
            }
        }
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0) {
            return false;
        }
        TreeNode *root = NULL;
        int len = nums.size();
        if (len < 2) {
            return false;
        }
        for (int i = 0; i < len; i ++) {
            if (!insertNode(&root, nums[i], i, k, t)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums(2, -1);
    Solution solution;
    cout << solution.containsNearbyAlmostDuplicate(nums, 1, -1) << endl;
}
