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
private:
    //flatten and return tail
    TreeNode* flattenR(TreeNode* root){
        if(!root) return NULL;
        if((!root->left)&&(!root->right)) return root;
        TreeNode *tailL, *tailR;
        
        tailR =flattenR(root->right);
        
        if(root->left){
          tailL = flattenR(root->left);
          tailL->right = root->right;
          root->right = root->left;
          root->left = NULL;
        } 
        
        return tailR?tailR:tailL;
    }    
public:
    void flatten(TreeNode* root) {
         flattenR(root);
    }
};
