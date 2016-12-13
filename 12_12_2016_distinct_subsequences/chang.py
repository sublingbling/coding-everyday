class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        """if s is None or t is None or len(s) == 0 or len(t) == 0:
            return 0"""
        dp = [[0 for x in xrange(len(t) + 1)] for y in xrange(len(s) + 1)]
        
        for i in xrange(len(s) + 1):
            dp[i][0] = 1
        
        for i in xrange(1, len(s) + 1):
            for j in xrange(1, len(t) + 1):
                if s[i-1] == t[j-1]:
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
                else: 
                    dp[i][j] = dp[i-1][j]
        
        return dp[len(s)][len(t)]
