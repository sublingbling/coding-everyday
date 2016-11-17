class Solution:
    """
    @param A: a list of integer
    @return: a tree node
    """
    def sortedArrayToBST(self, A):
        if A is None or len(A) == 0:
            return None
        
        mid = len(A) / 2
        
        root = TreeNode(A[mid])
        
        root.left = self.sortedArrayToBST(A[0:mid])
        root.right = self.sortedArrayToBST(A[mid+1:len(A)])
        
        return root
