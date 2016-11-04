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
   
public:
    TreeNode* invertTree(TreeNode* root) {
        if(NULL == root) return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* r = q.front();
            q.pop();
            TreeNode* t = r->left;
            r->left = r->right;
            r->right = t;
            if(r->left) q.push(r->left);
            if(r->right) q.push(r->right);
        }
        
        return root;
    }
};

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
   
public:
    TreeNode* invertTree(TreeNode* root) {
        if(NULL == root) return root;
        TreeNode* t = root->left;
        root->left = root->right;
        root->right = t;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
