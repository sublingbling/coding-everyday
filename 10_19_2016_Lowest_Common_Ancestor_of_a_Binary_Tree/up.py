# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        
        # check none node
        if not root:
            return root
            
        # if root is p or q, return root as a valid node
        if root == p or root == q: 
            return root
            
        # root is not p or q, check root.left and root.right
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        
        # left and right both contain pq, pass the root as LCA 
        if left and right:
            return root
        # just left has pq, pass pq
        elif left:
            return left
        # just right has pq, pass pq
        elif right:
            return right
        # nothing in the child nodes, return None
        else:
            return None
       
