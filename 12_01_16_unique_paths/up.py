class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if m <1 or n<1 :
            return 0
        
        if m == 1 or n == 1:
            return 1
        
        # now both n and m are larger than 1 
        short = min(m-1,n-1)
        dividend = m - 1 + n -1
        divisor = short
        for i in xrange(1, short):
            dividend *= m - 1 + n -1 -i
            divisor *= i
        
        return  dividend / divisor
