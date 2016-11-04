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
        vector<string> r;
        if(NULL == root) return r;
        string s = to_string(root->val);
        
        if(root->left){
            for(auto a: binaryTreePaths(root->left)){
                r.push_back(s+"->"+a);
            }
        }
        if(root->right){
            for(auto a: binaryTreePaths(root->right)){
                r.push_back(s+"->"+a);
            }
        }
        
        if(root->left || root->right) return r;
        
        r.push_back(s);
        
        return r;
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
    vector<string> v_s;
    void bTreePath(TreeNode* root, string& s){
        if(NULL == root) return;
        int count = s.size();
        s += to_string(root->val);
        if(!root->left&&!root->right){
            v_s.push_back(s);
            s.erase(s.begin()+count,s.end());
            return;
        }
        s += "->";
        if(root->left) bTreePath(root->left, s);
        if(root->right) bTreePath(root->right, s);
        s.erase(s.begin()+count,s.end());
        return;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
        bTreePath(root, s);
        return v_s;
    }
};
