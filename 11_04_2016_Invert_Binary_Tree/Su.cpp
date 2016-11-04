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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        TreeNode * tmp = root->left;
        root->left=root->right;
        root->right=tmp;
        invertTree(root->left);
        invertTree(root->right);
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
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> nodes;
        nodes.push(root);
        while(nodes.size() && root){
            TreeNode* roottmp=nodes.top();
            nodes.pop();
            TreeNode* tmp=roottmp->left;
            roottmp->left=roottmp->right;
            roottmp->right=tmp;
            if(roottmp->left) nodes.push(roottmp->left);
            if(roottmp->right) nodes.push(roottmp->right);
        }
        return root;
    }
};
