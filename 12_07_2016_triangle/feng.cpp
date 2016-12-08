class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> sum = triangle;
        if(triangle.empty()) return 0;
        for(int i= triangle.size()-2;i>=0;i--){
            for(int j=0; j<triangle[i].size(); j++){
                sum[i][j] += min(sum[i+1][j],sum[i+1][j+1]);
            }
        }
        return sum[0][0];
    }
};
