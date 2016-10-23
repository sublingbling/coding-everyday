/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */
public class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    public boolean isValidBST(TreeNode root) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        inOrderT(root, list);
        
        for (int i = 1; i < list.size(); i++) {
            if (list.get(i-1) >= list.get(i)) {
                return false;
            }
        }
        return true;


    }
    
    private void inOrderT(TreeNode root, ArrayList<Integer> list) {
        //special case
        if (root == null) {
            return;
        }
        //left
        if (root.left != null) {
            inOrderT(root.left, list);
        }
        
        list.add(root.val);
        
        if (root.right != null) {
            inOrderT(root.right, list);
        }
        
        
    }
}
