class Solution:
    """
    @param grid: a list of lists of integers.
    @return: An integer, minimizes the sum of all numbers along its path
    """
    def minPathSum(self, grid):
        if grid is None or len(grid) == 0 or len(grid[0]) == 0:
            return 0
            
        for i in xrange(len(grid)):
            for j in xrange(len(grid[0])):
                if i == 0 and j ==0:
                    grid[i][j] = grid[i][j]
                elif i == 0:
                    grid[i][j] = grid[i][j-1] + grid[i][j]
                elif j == 0:
                    grid[i][j] = grid[i-1][j] + grid[i][j]
                else:
                    grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j]
                    
        return grid[-1][-1]
        
