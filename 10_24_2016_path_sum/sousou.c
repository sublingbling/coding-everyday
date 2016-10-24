/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    if (!root) return false;
    if ((!root->left) && (!root->right) && (sum==root->val))
        return true;

    bool retVal = hasPathSum(root->left, sum-root->val);
    return retVal |= hasPathSum(root->right, sum-root->val);
}
