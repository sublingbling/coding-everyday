class Solution {
    bool _countIslands(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return false;
        }
        if (grid[i][j] == 'x' || grid[i][j] == '0') {
            return false;
        }
        grid[i][j] = 'x';
        _countIslands(grid, i + 1, j);
        _countIslands(grid, i - 1, j);
        _countIslands(grid, i, j + 1);
        _countIslands(grid, i, j - 1);
        return true;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int height = grid.size();
        if (!height) {
            return 0;
        }
        int width = grid[0].size();
        if (!width) {
            return 0;
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                bool foundNewIsland = _countIslands(grid, i, j);
                if (foundNewIsland) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
