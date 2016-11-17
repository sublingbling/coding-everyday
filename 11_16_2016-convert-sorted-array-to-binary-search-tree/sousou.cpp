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
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (0 == nums.size()) return NULL;
        
        int mid = nums.size()/2;
        TreeNode* root = new TreeNode(nums[mid]);

        vector<int> left (nums.begin(), nums.begin()+mid);
        root->left = sortedArrayToBST(left);

        vector<int> right (nums.begin()+mid+1, nums.end());
        root->right = sortedArrayToBST(right);
        
        return root;
    }
};
