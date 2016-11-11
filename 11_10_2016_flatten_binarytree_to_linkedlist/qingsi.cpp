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
        if (!root) {
            return;
        }
        vector<TreeNode*> st;
        st.push_back(root) ;
        while (st.size()) {
            TreeNode* node = st.back();
            st.pop_back();
            if (node->right) {
                st.push_back(node->right);
            }
            if (node->left) {
                st.push_back(node->left);
            }
            node->left = NULL;
            if (st.size()) {
                node->right = st.back();
            } else {
                node->right = NULL;
            }
            
        }
    }
};
