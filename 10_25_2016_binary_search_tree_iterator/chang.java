public class BSTIterator {
    //@param root: The root of binary tree.
    private Stack<TreeNode> stack = new Stack<TreeNode>();
    private TreeNode cur;
    
    public BSTIterator(TreeNode root) {
        // 
        cur = root;
    }

    //@return: True if there has next node, or false
    public boolean hasNext() {
        // 
        return (cur != null || !stack.isEmpty());
    }
    
    //@return: return next node
    public TreeNode next() {
        while (cur != null) {
            stack.push(cur);
            cur = cur.left;
        }
        
        TreeNode next = stack.pop();
        cur = next;
        cur = cur.right;
        
        return next;
        
        
    }
}
