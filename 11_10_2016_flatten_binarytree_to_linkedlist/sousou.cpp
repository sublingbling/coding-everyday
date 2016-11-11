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
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode *next = flattenSub(root->left, root);
        flattenSub(root->right, next);
        
        while (root->left)
        {
            root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }
    
    TreeNode* flattenSub(TreeNode* root, TreeNode* prev)
    {
        if (!root) return prev;
        prev->left = root;
        
        TreeNode *next = flattenSub(root->left, root);
        return flattenSub(root->right, next);
        
    }
};
