class Solution:
    """
    @param n and m: positive integer(1 <= n , m <= 100)
    @return an integer
    """ 
    def uniquePaths(self, m, n):
        if m == 0 or n == 0:
            return 0
            
        A = [[1 for x in range(n)] for x in range(m)]
            
        '''for i in range(0, m):
            A[i][0] = 1
        for i in range(0, n):
            A[0][i] = 1'''
        
        for i in range(1, m):
            for j in range(1, n):
                A[i][j] = A[i-1][j] + A[i][j-1]
                
        return A[-1][-1]
