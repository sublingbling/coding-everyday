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
        vector<TreeNode*> preOrder;
        vector<int> result;
        if(root==NULL) return result;
        
        preOrder.push_back(root);
        while(preOrder.size()){
            int id = preOrder.size()-1;
            root=preOrder[id];
            preOrder.pop_back();
            result.push_back(root->val);
            if(root->right) preOrder.push_back(root->right);
            if(root->left) preOrder.push_back(root->left);
        }
        
        return result;
    }
};
