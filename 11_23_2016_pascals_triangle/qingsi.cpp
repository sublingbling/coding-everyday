class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rows(numRows);
        for (int i = 0; i < numRows; i++) {
            rows[i].resize(i+1);
            rows[i][0] = 1;
            rows[i][i] = 1;
            for (int j = 1; j < i; j++) {
                rows[i][j] = rows[i-1][j-1] + rows[i-1][j];
            }
        }
        return rows;
    }
};
