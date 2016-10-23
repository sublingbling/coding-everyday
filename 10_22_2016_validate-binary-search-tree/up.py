# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        def inOrd(root, output):
            if root is None:
                return
            
            inOrd(root.left, output)
            output.append(root.val)
            inOrd(root.right, output)
            return 
    
        # inorder traverse bst then check order
        l = []
        inOrd(root, l)
        
        # check order
        for i in xrange(1, len(l)):
            if l[i-1] >= l[i]:
                return False

        return True
