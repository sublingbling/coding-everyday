class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        if not root:
            return
        
        right = root.right
        self.flatten(right)
            
        root.right = root.left
        self.flatten(root.right)
        
        head = root.right
        if head:
            while head.right:
                head = head.right
            head.right = right
        else:
            root.right = right
        
        root.left = None
