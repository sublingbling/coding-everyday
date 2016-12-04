# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        
        def MPS(root):
            """
            rtype: max side of path and max path
            """
            if not root:
                return 0, -sys.maxint - 1 
                
            pL, pLM = MPS(root.left)
            pR, pRM = MPS(root.right)
            
            if pL < 0 : pL = 0
            if pR < 0 : pR = 0
            
            sP, mP = max(pL, pR) + root.val, max(pLM,pRM,root.val + pL + pR)
            return sP, mP
            
        
        if not root:
            return 0
        else:
            return MPS(root)[1]
