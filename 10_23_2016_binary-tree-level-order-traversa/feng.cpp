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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> r_v;
        vector<int> r;
        if(root==NULL) return r_v;
        queue<TreeNode*> q;
        q.push(root);
        int count=1;
        int countNext = 0;
        while(!q.empty()){
            if(count>0){
                TreeNode* t = q.front();
                q.pop();
                r.push_back(t->val);
                if(t->left) {q.push(t->left);countNext++;}
                if(t->right) {q.push(t->right); countNext++;}
                count --;
            }
            else{
                count=countNext;
                countNext=0;
                r_v.push_back(r);
                r.clear();
            }
        }
        r_v.push_back(r);
        return r_v;
    }
};
