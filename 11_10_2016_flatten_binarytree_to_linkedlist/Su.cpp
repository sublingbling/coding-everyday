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
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        stack<TreeNode*> s;
        TreeNode* node=root;
		TreeNode* nodeparent=NULL;
        s.push(node);
        while(s.size()){
            node=s.top();
            s.pop();
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
			if(nodeparent){
				nodeparent->left=NULL;
				nodeparent->right=node;
			}
			nodeparent=node;
        }
    }
};
