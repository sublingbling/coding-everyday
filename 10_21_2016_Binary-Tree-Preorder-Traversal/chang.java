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
 //divide and conquer
public class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in ArrayList which contains node values.
     */
    public ArrayList<Integer> preorderTraversal(TreeNode root) {
        // recursive dc
        ArrayList<Integer> result = new ArrayList<Integer>();
        
        if (root == null) {
            return result;
        }
        
        ArrayList<Integer> left = preorderTraversal(root.left);
        ArrayList<Integer> right = preorderTraversal(root.right);
        
        result.add(root.val);
        result.addAll(left);
        result.addAll(right);
        
        return result;
    }
}
/*-----------------*/
//traversal
public class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in ArrayList which contains node values.
     */
    public ArrayList<Integer> preorderTraversal(TreeNode root) {
        // recursive 
        ArrayList<Integer> result = new ArrayList<Integer>();
        traversal(root, result);
        return result;

    }
    
    private void traversal(TreeNode root, ArrayList<Integer> result) {
        if (root == null) {
            return;
        }
        result.add(root.val);
        traversal(root.left, result);
        traversal(root.right, result);
        return;
    }
}
/*------------------*/
//non-recursive

