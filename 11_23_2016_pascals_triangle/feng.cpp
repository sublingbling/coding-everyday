class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows);
        for(int i=0; i<numRows;i++){
            for(int j=0; j<=i; j++){
                if(j==0||j==i) r[i].push_back(1);
                else r[i].push_back(r[i-1][j-1]+r[i-1][j]);
            }
        }
        return r;
    }
};
