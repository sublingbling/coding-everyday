class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rows;
        if (!numRows) {
            return rows;
        }
        rows.push_back(vector<int>(1, 1));
        for (int i = 1; i < numRows; i++) {
            vector<int> row(i+1, 1);
            for (int j = 0; j < rows[i-1].size() - 1; j++) {
                row[j+1] = rows[i-1][j] + rows[i-1][j+1];
            }
            rows.push_back(row);
        }
        return rows;
    }
};
