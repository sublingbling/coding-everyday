# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        
        # height info needed to check balance
        def isBalancedWithHeight(root):
            """
            :type root: TreeNode
            :rtype: int
            """
            # none -> height 0
            if not root :
                return 0
            else :
                # root is valid, check left height and right height
                leftHeight = isBalancedWithHeight(root.left) 
                rightHeight = isBalancedWithHeight(root.right) 
                
                # if left/right not balanced, or current root is not balanced, return -1, which means unbalanced.
                if abs(leftHeight - rightHeight) > 1 or leftHeight == -1 or rightHeight == -1:
                    return -1
                else:
                    # balanced, now return height info 
                    return max(leftHeight, rightHeight) + 1
        
        return isBalancedWithHeight(root) != -1
                
        
        
