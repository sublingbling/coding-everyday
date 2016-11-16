class Solution:
    # @param {boolean[][]} grid a boolean 2D matrix
    # @return {int} an integer
    def numIslands(self, grid):
    
        if grid is None or len(grid) == 0 or len(grid[0]) == 0:
            return 0
        count = 0
        rowN = len(grid)
        colN = len(grid[0])
        
        for i in xrange(rowN):
            for j in xrange(colN):
                if grid[i][j] == 1:
                    count += 1
                    self.DFS(grid, i, j, rowN, colN)
        return count
    
    # search all the connected components and mark them as 0
    def DFS(self, grid, i, j, rowN, colN):
        if i < 0 or j < 0 or i >= rowN or j >= colN or grid[i][j] == 0:
            return
        grid[i][j] = 0
        self.DFS(grid, i-1, j, rowN, colN)
        self.DFS(grid, i+1, j, rowN, colN)
        self.DFS(grid, i, j-1, rowN, colN)
        self.DFS(grid, i, j+1, rowN, colN)
