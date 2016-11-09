class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        if n < 2 :
            return n
        
        # now n>=2
        dp = [1] * (n + 1)
        for i in xrange(2,n + 1):
            dp[i] = dp[i-2] + dp[i-1]
        
        return dp[n]
