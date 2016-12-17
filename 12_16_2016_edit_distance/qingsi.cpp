class Solution {
    vector<vector<int>> DP;
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        DP = vector<vector<int>>(n+1, vector<int>(m+1, 0));
        for (int i = 0; i < n+1; i++) {
            for (int j = 0; j < m+1; j++) {
                if (i == 0) {
                    DP[i][j] = j;
                } else if (j == 0) {
                    DP[i][j] = i;
                } else {
                    if (word1[i-1] == word2[j-1]) {
                        DP[i][j] = DP[i-1][j-1];
                    } else {
                        DP[i][j] = min(min(1 + DP[i-1][j], 1 + DP[i][j-1]), 1 + DP[i-1][j-1]);
                    }
                }
            }
        }
        return DP[n][m];
    }
};
