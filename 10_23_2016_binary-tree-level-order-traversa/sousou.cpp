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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> retVec;
        if (!root) return retVec;
        
        vector<int> currVec;
        currVec.push_back(root->val);
        retVec.push_back(currVec);
        
        int level = 1;
        levelOrderSub(root->left, level, retVec);
        levelOrderSub(root->right, level, retVec);
        
        return retVec;
    }
    
    void levelOrderSub(TreeNode* root, int level, vector<vector<int>> &retVec)
    {
        if (!root) return;
        
        vector<int> currLevel;
        if (level >= retVec.size())
            retVec.push_back(currLevel);
        retVec[level++].push_back(root->val);
        
        levelOrderSub(root->left, level, retVec);
        levelOrderSub(root->right, level, retVec);
        
        return;
    }
    
};
