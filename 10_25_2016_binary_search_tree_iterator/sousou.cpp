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
    stack<TreeNode*> myStack;
public:
    BSTIterator(TreeNode *root) {
        while (root)
        {
            myStack.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *topNode = myStack.top();
        TreeNode *pushNode = topNode->right;
        myStack.pop();
        while (pushNode)
        {
            myStack.push(pushNode);
            pushNode = pushNode->left;
        }
        return topNode->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
