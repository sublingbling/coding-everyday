class Solution:
    """
    @param n: An integer
    @return: An integer
    """
    def climbStairs(self, n):
        if n < 2:
            return 1
            
        fb = [1 for x in range(n+1)]
        
        for i in range(2,n+1):
            fb[i] = fb[i-1] + fb[i-2]
        
        return fb[n]
