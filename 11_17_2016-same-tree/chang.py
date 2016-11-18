class Solution:
    """
    @param a, b, the root of binary trees.
    @return true if they are identical, or false.
    """
    def isIdentical(self, a, b):
        if a is None and b is None:
            return True
        if a is None or b is None or a.val != b.val:
            return False
        
        boolean1 = self.isIdentical(a.left, b.left)
        boolean2 = self.isIdentical(a.right, b.right)
        
        return boolean1 and boolean2
