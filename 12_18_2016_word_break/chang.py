class Solution:
    # @param s: A string s
    # @param dict: A dictionary of words dict
    def wordBreak(self, s, dict):
        if len(dict) == 0:
            return len(s) == 0
        
        dp = [False] * (len(s) + 1)
        dp[0] = True
        
        maxLength = max([len(x) for x in dict])
        
        for i in xrange(1, len(s) + 1):
            for j in xrange(1, min(i, maxLength) + 1):
                if not dp[i - j]:
                    continue
                if s[i - j:i] in dict:
                    dp[i] = True
                    break
                    
        return dp[len(s)]
