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
private:
    queue<TreeNode*> nodes;
public:
    BSTIterator(TreeNode *root) {
        stack<TreeNode*> orderstack;
        while(orderstack.size() || root){
            if(root){
                orderstack.push(root);
                root=root->left;
            }else{
                root=orderstack.top();
                orderstack.pop();
                nodes.push(root);
                root=root->right;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodes.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmp = nodes.front();
        nodes.pop();
        return tmp->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
