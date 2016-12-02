class Solution {
    vector<vector<int>> DP;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (!m) {
            return 0;
        }
        int n = obstacleGrid[0].size();
        if (!n) {
            return 0;
        }
        DP = vector<vector<int>>(m, vector<int>(n, 1));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    DP[i][j] = 0;
                } else if (i == m-1) {
                    DP[i][j] = DP[i][min(j+1, n-1)];
                } else if (j == n-1) {
                    DP[i][j] = DP[min(i+1, m-1)][j];
                } else {
                    DP[i][j] = DP[i+1][j] + DP[i][j+1];
                }
            }
        }
        return DP[0][0];
    }
};
