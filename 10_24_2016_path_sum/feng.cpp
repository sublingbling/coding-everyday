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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        sum -= root->val;
        if((NULL==root->left) && (NULL==root->right)) return sum==0;
        bool r=false;
        if(root->left) r = r || hasPathSum(root->left,sum);
        if(root->right) r = r || hasPathSum(root->right,sum);
        return r;
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        sum -= root->val;
        if((NULL==root->left) && (NULL==root->right)) return sum==0;
        return hasPathSum(root->left,sum) || hasPathSum(root->right,sum);
    }
};
