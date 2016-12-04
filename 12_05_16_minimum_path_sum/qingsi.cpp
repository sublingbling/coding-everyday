class Solution {
    vector<vector<int>> DP;
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        if (n == 0) {
            return 0;
        }
        DP = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i == m-1 && j == n-1) {
                    DP[m-1][n-1] = grid[m-1][n-1];
                } else if (i == m-1) {
                    DP[i][j] = grid[i][j] + DP[i][j+1];
                } else if (j == n-1) {
                    DP[i][j] = grid[i][j] + DP[i+1][j];
                } else {
                    DP[i][j] = grid[i][j] + min(DP[i][j+1], DP[i+1][j]);
                }
            }
        }
        return DP[0][0];
    }
};
