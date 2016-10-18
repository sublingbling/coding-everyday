/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findHeight(struct TreeNode* root)
{
    if (!root) return 0;

    int leftHeight = 0, rightHeight = 0, height = 0;
    
    height = findHeight(root->left);
    if (-1==height) return -1;
    else leftHeight = 1+height;
    
    height = findHeight(root->right);
    if (-1==height) return -1;
    else rightHeight = 1+height;
    
    if (abs(leftHeight-rightHeight)>1) return -1;
    else return leftHeight > rightHeight ? leftHeight : rightHeight;
    
}

bool isBalanced(struct TreeNode* root) {
    if (!root) return true;

    if (-1 != findHeight(root)) return true;
    else return false;
}
