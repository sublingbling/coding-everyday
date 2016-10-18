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
    int Height(TreeNode* root){
        if(!root) return -1;
        return max(Height(root->left), Height(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        return !root || (isBalanced(root->left) && isBalanced(root->right) && abs(Height(root->left)-Height(root->right))<=1);
    }
};
