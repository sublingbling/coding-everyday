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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root==NULL) return result;
        if(root->left==NULL && root->right==NULL){
            ostringstream oss;
            oss<< root->val;
            result.push_back(oss.str());
            return result;
        }
        vector<string> res1,res2;
        if(root->left) res1=binaryTreePaths(root->left);
        if(root->right) res2=binaryTreePaths(root->right);
        for(int i=0;i<res1.size();i++){
            ostringstream oss;
            oss<< root->val;
            string s;
            s=oss.str()+"->";
            s+=res1[i];
            result.push_back(s);
        }
         for(int i=0;i<res2.size();i++){
            ostringstream oss;
            oss<< root->val;
            string s;
            s=oss.str()+"->";
            s+=res2[i];
            result.push_back(s);
        }
        
        return result;
    }
};
