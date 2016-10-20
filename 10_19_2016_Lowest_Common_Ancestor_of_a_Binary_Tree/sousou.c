/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
struct TreeNode* lowestCommonAncestorSub(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q, bool *foundp, bool *foundq)
{
    if (root==p) *foundp = true;
    else if (root==q) *foundq = true;
    
    struct TreeNode *retNode = NULL;
    bool foundpSub = false, foundqSub = false;
    
    if (root->left)
    {
        retNode = lowestCommonAncestorSub(root->left, p, q, &foundpSub, &foundqSub);
        if (retNode) return retNode;
    }
    
    *foundp = *foundp || foundpSub;
    *foundq = *foundq || foundqSub;
    foundpSub = false;
    foundqSub = false;
    if (root->right)
    {
        retNode = lowestCommonAncestorSub(root->right, p, q, &foundpSub, &foundqSub);
        if (retNode) return retNode;
    }
    
    *foundp = *foundp || foundpSub;
    *foundq = *foundq || foundqSub;
    
    if (*foundp && *foundq) return root;
    else return NULL;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root || !p || !q) return root;
    
    bool foundp = false, foundq = false;
    return lowestCommonAncestorSub(root, p, q, &foundp, &foundq);
}
