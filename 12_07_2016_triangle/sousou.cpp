class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> myvector = triangle.back();
        for (int i=triangle.size()-2; i>=0; i--)
        {
            for (int j=0; j<=i; j++)
            {
                myvector[j] = min(triangle[i][j]+myvector[j], triangle[i][j]+myvector[j+1]);
            }
        }
        return myvector[0];
    }
};
