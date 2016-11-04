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
    vector<string> TreePath;
    
    void binaryTreePathsAddPath(TreeNode* root, string LastPath)
    {
        string currPath = LastPath + "->" + to_string(root->val);
        if (!root->left && !root->right)
        {
            TreePath.push_back(currPath);
            return;
        }
        if (root->left)
            binaryTreePathsAddPath(root->left, currPath);
        if (root->right)
            binaryTreePathsAddPath(root->right, currPath);
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return TreePath;
        
        string path (to_string(root->val));
        if (!root->left && !root->right)
        {
            TreePath.push_back(path);
            return TreePath;
        }
        if (root->left)
            binaryTreePathsAddPath(root->left, path);
        if (root->right)
            binaryTreePathsAddPath(root->right, path);
        
        return TreePath;
    }
};
