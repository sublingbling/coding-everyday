class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (!m) {
            return res;
        }
        int n = matrix[0].size();
        if (!n) {
            return res;
        }
        int top = 0;
        int bottom = m;
        int left = 0;
        int right = n;
        while (top < bottom && left < right) {
            for (int i = left; i < right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i < bottom; i++) {
                res.push_back(matrix[i][right-1]);
            }
            right--;
            if (top >= bottom || left >= right) {
                break;
            }
            for (int i = right-1; i >= left; i--) {
                res.push_back(matrix[bottom-1][i]);
            }
            bottom--;
            for (int i = bottom-1; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};
