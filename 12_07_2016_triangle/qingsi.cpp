class Solution {
    vector<int> DP;
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int numRows = triangle.size();
        if (numRows == 0) {
            return 0;
        }
        DP = triangle.back();
        for (int i = numRows-2; i >= 0; i--) {
            for (int j = 0; j < i+1; j++) {
                DP[j] = min(triangle[i][j] + DP[j], triangle[i][j] + DP[j+1]);
            }
        }
        return DP[0];
    }
};
