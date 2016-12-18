class Solution:
    # @param s, a string
    # @return an integer
    def minCut(self, s):
        if not s or len(s) == 0:
            return 0
        isPar = self.isPalindrome(s)
        
        dp = []
        for i in xrange(len(s) + 1):
            dp.append(i - 1)
            
        for i in xrange(1, len(s) + 1):
            for j in xrange(i):
                if isPar[j][i - 1]:
                    dp[i] = min(dp[i], dp[j] + 1)
                    
        return dp[len(s)]
        
    def isPalindrome(self, s):
        slen = len(s)
        isPal = [[False for x in range(slen)] for y in range(slen)]
        
        for i in xrange(slen):
            isPal[i][i] = True
            
        for i in xrange(slen - 1):
            isPal[i][i + 1] = (s[i] == s[i + 1])
            
        for length in xrange(2, slen):
            for start in xrange(slen - length):
                isPal[start][start + length] = isPal[start + 1][start + length -1] and (s[start] == s[start + length])
                
        return isPal
            
