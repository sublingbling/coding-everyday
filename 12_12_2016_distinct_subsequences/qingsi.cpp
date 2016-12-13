class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        int DP[m+1][n+1] = {0};
        for (int i = 0; i < m+1; i++) {
            for (int j = 0; j < n+1; j++) {
                if (i == 0 && j > 0) {
                    DP[i][j] = 0;
                } else if (j == 0) {
                    DP[i][j] = 1;
                } else if (s[i-1] == t[j-1]) {
                    DP[i][j] = DP[i-1][j-1] + DP[i-1][j];
                } else {
                    DP[i][j] = DP[i-1][j];
                }
            }
        }
        return DP[m][n];
    }
};
