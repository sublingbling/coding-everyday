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
    int max_sum;
    //for each node, the max could be 
    // case can't pass to the parents (which means maxL and maxR don't not include those two case, it will go through max_sum)
    //1. node->val+maxL+maxR
    //2. max(maxL,maxR)
    // case can pass to parents
    //3. node->val;
    //4. node->val+max(maxL,maxR)
    int maxPathSumR(TreeNode* root){ //root won't be NULL
        if(!root->left && !root->right) return root->val;
        else if(root->left&&root->right){
            int maxL=maxPathSumR(root->left);
            int maxR=maxPathSumR(root->right);
            max_sum = max(max_sum,maxL);
            max_sum = max(max_sum,maxR);
            max_sum = max(max_sum,maxL+maxR+root->val);
            return max(root->val, root->val+max(maxL,maxR));
        }
        else if(root->left){
            int maxL=maxPathSumR(root->left);
            max_sum = max(max_sum,maxL);
            return max(root->val, root->val+maxL);
        }
        else{//root->right
            int maxR=maxPathSumR(root->right);
            max_sum = max(max_sum,maxR);
            return max(root->val, root->val+maxR);
        }
    } 
public:
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        max_sum=root->val;
        return max(max_sum, maxPathSumR(root));
    }
};
