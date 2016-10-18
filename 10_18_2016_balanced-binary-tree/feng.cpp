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
    int getHeight(TreeNode* root){
        if(root == NULL) return 0;
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        if((l==-1)||(r==-1)) return -1;
        if(abs(l-r)>1) return -1;
        return max(l,r)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        int h = getHeight(root);
        if(h==-1) return false;
        return true;
    }
};
