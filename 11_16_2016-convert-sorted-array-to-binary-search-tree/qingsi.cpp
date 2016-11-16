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
    TreeNode* _sortedArrayToBST(vector<int>& nums, int begin, int length) {
        if (!length) {
            return NULL;
        }
        int mid = begin + length / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        TreeNode* left = _sortedArrayToBST(nums, begin, length/2);
        TreeNode* right = _sortedArrayToBST(nums, mid+1, length - length/2 - 1);
        root->left = left;
        root->right = right;
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _sortedArrayToBST(nums, 0, nums.size());
    }
};

class SolutionAlternative {
    int _idx = 0;
    vector<int> _nums;
    TreeNode* buildTree(int numNodes) {
        if (!numNodes)
            return NULL;
        if (numNodes == 1) {
            auto root = new TreeNode(-1);
            return root;
        }
        if (numNodes == 2) {
            auto root = new TreeNode(-1);
            auto leaf = new TreeNode(-1);
            root->left = leaf;
            return root;
        }
        auto root = new TreeNode(-1);
        auto leftChild = buildTree(numNodes/2);
        auto rightChild = buildTree(numNodes - 1 - numNodes/2);
        root->left = leftChild;
        root->right = rightChild;
        return root;
    }
    void labelTree(TreeNode* root) {
        if (!root)
            return;
        if (root->left)
            labelTree(root->left);
        root->val = _nums[_idx++];
        if (root->right)
            labelTree(root->right);
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        auto root = buildTree(nums.size());
        if (!root)
            return root;
        _nums.assign(nums.begin(), nums.end());
        labelTree(root);
        return root;
    }
};
