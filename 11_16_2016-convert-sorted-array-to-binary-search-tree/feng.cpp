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
    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r){
        if(l>r) return NULL;
        else if(l==r) return new TreeNode(nums[l]);
        else{
            int m=(l+r)/2;
            TreeNode* head = new TreeNode(nums[m]);
            head->left = sortedArrayToBST(nums, l, m-1);
            head->right = sortedArrayToBST(nums,m+1,r);
            return head;
        }
        
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
}
