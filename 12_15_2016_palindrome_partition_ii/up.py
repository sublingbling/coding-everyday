class Solution(object):
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        cut = [x for x in range(-1,len(s))]
        
        for i in range(0,len(s)):
            for j in range(i,len(s)):
                if s[i:j] == s[j:i:-1]:
                    cut[j+1] = min(cut[j+1],cut[i]+1)
        return cut[-1]
