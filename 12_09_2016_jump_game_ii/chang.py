class Solution:
    # @param A, a list of integers
    # @return an integer
    def jump(self, A):
        if A is None or len(A) == 0:
            return 0
            
        bound = 0
        maxBound = 0
        jump = 0
        
        for i in xrange(len(A) - 1):
            maxBound = max(A[i] + i, maxBound)
            if i == bound:
                jump += 1
                bound = maxBound
                
        return jump
