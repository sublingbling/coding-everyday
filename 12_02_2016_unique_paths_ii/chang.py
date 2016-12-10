class Solution:
    """
    @param obstacleGrid: An list of lists of integers
    @return: An integer
    """
    def uniquePathsWithObstacles(self, obstacleGrid):
        if obstacleGrid is None or len(obstacleGrid) == 0 or len(obstacleGrid[0]) == 0:
            return 0
            
        A = obstacleGrid
        
        for i in range(len(A)):
            for j in range(len(A[0])):
                if i == 0 and j == 0:
                    A[i][j] = 1 - A[i][j]
                elif i == 0:
                    if A[i][j] == 1:
                        A[i][j] = 0
                    else:
                        A[i][j] = A[i][j-1]
                elif j == 0:
                    if A[i][j] == 1:
                        A[i][j] = 0
                    else:
                        A[i][j] = A[i-1][j]
                else:
                    if A[i][j] == 1:
                        A[i][j] = 0
                    else:
                        A[i][j] = A[i-1][j] + A[i][j-1]
        
        return A[-1][-1]
