class Solution:
    """
    @param triangle: a list of lists of integers.
    @return: An integer, minimum path sum.
    """
    def minimumTotal(self, triangle):
        if triangle is None or len(triangle) == 0 or len(triangle[-1]) == 0:
            return 0
        
        for i in xrange(len(triangle)):
            for j in xrange(i+1):
                if i == 0 and j == 0:
                    triangle[i][j] = triangle[i][j]
                elif j == 0:
                    triangle[i][j] += triangle[i-1][j]
                elif j == i:
                    triangle[i][j] += triangle[i-1][j-1]
                else:
                    triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1])
        
        """minVal = sys.maxint            
        for j in xrange(len(triangle[-1])):
            minVal = min(minVal, triangle[-1][j])"""
        minVal = min(triangle[-1])
            
        return minVal
