# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        re = []
        stack = [root]
        
        while stack:
            # create value and node lists for current level
            curRe, curStack = [], []
            for node in stack:
                if node :
                    curRe.append(node.val)
                    curStack.append(node.left)
                    curStack.append(node.right)
            if curRe:
                re.append(curRe)
            stack = curStack
    
        return re
            
            
