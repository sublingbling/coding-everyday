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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        if(root==NULL) return preOrder;
        
        preOrder.push_back(root->val);
        vector<int> left=preorderTraversal(root->left);
        preOrder.insert(preOrder.end(),left.begin(),left.end());
        vector<int> right=preorderTraversal(root->right);
        preOrder.insert(preOrder.end(),right.begin(),right.end());
        return preOrder;
    }
};
