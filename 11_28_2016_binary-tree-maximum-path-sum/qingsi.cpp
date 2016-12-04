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
    map<TreeNode*, pair<int, int>> V = {{NULL, make_pair(-1, -1)}};
    void _populateValueFunction(TreeNode* root) {
        if (V.find(root) != V.end()) {
            return;
        }
        if (V.find(root->left) == V.end()) {
            _populateValueFunction(root->left);
        }
        if (V.find(root->right) == V.end()) {
            _populateValueFunction(root->right);
        }
        V[root].first = root->val + max(max(V[root->left].first, V[root->left].second), 0);
        V[root].second = root->val + max(max(V[root->right].first, V[root->right].second), 0);
    }
public:
    int maxPathSum(TreeNode* root) {
        _populateValueFunction(root);
        int res = INT_MIN;
        for (auto it = V.begin(); it != V.end(); it++) {
            if (!(it->first)) {
                continue;
            }
            //cout << (it->first)->val << ":" << (it->second).first << " " << (it->second).second << endl;
            int tmp = max(max((it->second).first, (it->second).second), (it->second).first + (it->second).second - (it->first)->val);
            if (tmp > res) {
                res = tmp;
            }
        }
        return res; 
    }
};
