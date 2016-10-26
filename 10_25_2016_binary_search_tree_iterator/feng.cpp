/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    queue<TreeNode*> q;
    void traversal(TreeNode* r){
        if(NULL == r) return;
        traversal(r->left);
        q.push(r);
        traversal(r->right);
    }
    
    BSTIterator(TreeNode *root) {
        traversal(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* r = q.front();
        q.pop();
        return r->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */