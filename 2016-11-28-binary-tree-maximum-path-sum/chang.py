"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""
class Solution:
    """
    @param root: The root of binary tree.
    @return: An integer
    """
    def maxPathSum(self, root):
        maxAnyToAny, _ = self.maxPathHelper(root)
        return maxAnyToAny
        
    def maxPathHelper(self, root):
        if root is None:
            # return anyToAny(contains at least one node) and rootToAny 
            return -sys.maxint, 0 
            
        left = self.maxPathHelper(root.left)
        right = self.maxPathHelper(root.right)
        
        rootToAny = max(0, root.val, root.val + left[1], root.val + right[1])
        anyToAny = max(left[0], right[0], left[1] + right[1] + root.val)
        
        return anyToAny, rootToAny
