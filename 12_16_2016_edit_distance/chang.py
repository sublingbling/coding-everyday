class Solution: 
    # @param word1 & word2: Two string.
    # @return: The minimum number of steps.
    def minDistance(self, word1, word2):
        if word1 is None or word2 is None or \
            (len(word1) == 0 and len(word2) == 0):
            return 0
            
        dp = [[0 for x in xrange(len(word2) + 1)] for y in xrange(len(word1) + 1)]
            
        for i in xrange(len(word1) + 1):
            for j in xrange(len(word2) + 1):
                if i == 0 and j == 0:
                    dp[0][0] = 0
                elif j == 0:
                    dp[i][0] = i
                elif i == 0:
                    dp[0][j] = j
                elif word1[i - 1] != word2[j - 1]:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], \
                        dp[i - 1][j - 1] ) + 1
                else: 
                    dp[i][j] = dp[i - 1][j - 1]
        
        return dp[len(word1)][(len(word2))]
