#DP method
class Solution:
    # @param A, a list of integers
    # @return a boolean
    def canJump(self, A):
        if A is None or len(A) == 0:
            return False
        
        DP = [False] * (len(A))
        DP[0] = True
        
        for i in xrange(1,len(A)):
            for j in xrange(i):
                if DP[j] is True and A[j] + j >= i:
                    DP[i] = True
                    break
                
        return DP[-1]
    
#Greedy
class Solution:
    # @param A, a list of integers
    # @return a boolean
    def canJump(self, A):
        if A is None or len(A) == 0:
            return False
        
        bound = A[0]
        
        for i in xrange(len(A)):
            if bound >= i:
                bound = max(A[i]+i, bound)
        
        if bound >= len(A) - 1:        
            return True
        else:
            return False  
    
