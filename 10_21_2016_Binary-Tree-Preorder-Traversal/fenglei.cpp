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
    void preorderTraveralRec(TreeNode* root, vector<int> &t){
        if(root==NULL) return;
        t.push_back(root->val);
        preorderTraveralRec(root->left, t);
        preorderTraveralRec(root->right, t);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderTraveralRec(root, result);
        return result;
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
        vector<int> r;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* t;
        while(!s.empty()){
            t = s.top();
            s.pop();
            if(t!=NULL){
                r.push_back(t->val);
                s.push(t->right);
                s.push(t->left);
            }
        }
        return r;
    }
};
