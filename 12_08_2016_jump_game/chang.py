class Solution:
    # @param A, a list of integers
    # @return a boolean
    def canJump(self, A):
        p = 0
        ans = 0
        for item in A[:-1]:
            ans = max(ans, p + item)
            if(ans <= p):
                return False
            p += 1
        return True
