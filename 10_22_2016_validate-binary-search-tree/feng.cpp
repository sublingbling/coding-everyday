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
    void inOrderTravel(TreeNode* r, vector<int>& v){
        if(r==NULL) return;
        inOrderTravel(r->left,v);
        v.push_back(r->val);
        inOrderTravel(r->right,v);
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        vector<int> v;
        inOrderTravel(root,v);
        
        for(int i=1;i<v.size();i++){
            if(v[i-1]>=v[i]) return false;
        }
        
        return true;
    }
};
