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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} 
};
    
    ListNode *head;
public:
    BSTIterator(TreeNode *root) {
        ListNode* cur=new ListNode(0);
        ListNode* curhead=cur;
        stack<TreeNode*> orderstack;
        while(orderstack.size() || root){
            if(root){
                orderstack.push(root);
                root=root->left;
            }else{
                root=orderstack.top();
                orderstack.pop();
                cur->next = new ListNode(root->val);
                cur=cur->next;
                root=root->right;
            }
        }
        head = curhead->next;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return head;
    }

    /** @return the next smallest number */
    int next() {
        int tmp=head->val;
        head=head->next;
        return tmp;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
