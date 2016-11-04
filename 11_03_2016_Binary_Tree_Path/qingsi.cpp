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
    void _getPaths(vector<string>& paths, string curr, TreeNode* root) {
        assert(root);
        if (!root->left && !root->right) {
            paths.push_back(curr);
            return;
        }
        if (root->left) {
            string next = curr + "->" + std::to_string(root->left->val);
            _getPaths(paths, next, root->left);
        }
        if (root->right) {
            string next = curr + "->" + std::to_string(root->right->val);
            _getPaths(paths, next, root->right);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (!root) {
            return paths;
        }
        string curr(std::to_string(root->val));
        _getPaths(paths, curr, root);
        return paths;
    }
};
