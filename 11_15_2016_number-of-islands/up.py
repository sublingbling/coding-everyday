class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if not grid:
            return 0
        # check rows# and cols#
        rowN, colN = len(grid), len(grid[0])
        islandN = 0
        stack = []
        for i in xrange(rowN):
            for j in xrange(colN):
                # if land, destroy it and search adjacent land
                if grid[i][j] == "1" :
                    islandN += 1
                    # find adjacent land
                    stack.append((i,j)) 
                    while stack:
                        print stack[0]
                        ii, jj = stack.pop()
                        grid[ii][jj] = 0
                        if ii and grid[ii-1][jj] == "1":
                           stack.append((ii-1,jj))
                        if ii < rowN - 1 and grid[ii+1][jj] == "1":
                           stack.append((ii+1,jj))
                        if jj and grid[ii][jj-1] == "1":
                           stack.append((ii,jj-1))
                        if jj < colN - 1 and grid[ii][jj+1] == "1":
                           stack.append((ii, jj+1))
                           
        return islandN
