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
        vector<int> retVector;
        preorderTraversalSub(root, retVector);
        return retVector;
    }
    
    void preorderTraversalSub(TreeNode* root, vector<int> &retVector) {
        if (!root) return;
        retVector.push_back(root->val);
        preorderTraversalSub(root->left, retVector);
        preorderTraversalSub(root->right, retVector);
    }
};
