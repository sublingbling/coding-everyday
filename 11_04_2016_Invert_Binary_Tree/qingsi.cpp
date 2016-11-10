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
    TreeNode* invertTreeRecursive(TreeNode* root) {
        if (!root) { return NULL; }
        if (!root->left && !root->right) { return root; }
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        tmp = invertTree(root->left);
        tmp = invertTree(root->right);
        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        if (!(root->left) && !(root->right)) {
            return root;
        }
        std::list<TreeNode*> q;
        q.push_back(root);
        while (q.size()) {
            TreeNode* node = q.front();
            q.pop_front();
            std::swap(node->left, node->right);
            if (node->right) {
                q.push_back(node->right);
            }
            if (node->left) {
                q.push_back(node->left);
            }
        }
        return root;
    }
};
