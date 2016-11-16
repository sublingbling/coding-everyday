/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* _sortedArrayToBST(vector<int>& nums, int begin, int length) {
        if (!length) {
            return NULL;
        }
        int mid = begin + length / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        TreeNode* left = _sortedArrayToBST(nums, begin, length/2);
        TreeNode* right = _sortedArrayToBST(nums, mid+1, length - length/2 - 1);
        root->left = left;
        root->right = right;
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _sortedArrayToBST(nums, 0, nums.size());
    }
};
