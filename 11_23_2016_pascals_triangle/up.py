class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        res = []
        
        for i in xrange(numRows):
            res += [[1]*(i+1)]
            if i > 1:
                for j in xrange(1,i):
                    res[i][j] = res[i-1][j-1] + res[i-1][j]
        
        return res
