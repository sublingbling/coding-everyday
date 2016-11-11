
class Solution {
public:
    void flatten(TreeNode* root) {
        flat(root);
    }
    TreeNode *flat(TreeNode *root) {
        if (!root) return NULL;
        if ( !root->left && !root->right ){
            return root;
        }
        if ( root->left == NULL ){
            return flat(root->right);
        }
        if ( root->right == NULL ) {
            root->right = root->left;
            root->left = NULL;
            return flat(root->right);
        }
        TreeNode *leftEnd = flat(root->left);
        TreeNode *rightEnd = flat(root->right);
        TreeNode *right = root->right;
        root->right = root->left;
        leftEnd->right = right;
        root->left = NULL;
        leftEnd->left = NULL;
        return rightEnd;
    }
};
