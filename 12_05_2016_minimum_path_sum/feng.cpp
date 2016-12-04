class Solution {
  
public:
    //BFS...
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int w=grid[0].size();
        int h=grid.size();
        int* path_sum = new int[w*h];
        path_sum[w*h-1] = grid[h-1][w-1];
        for(int i=h-1; i>=0; i--){
            for(int j=w-1; j>=0; j--){
                if(j==w-1 && i==h-1) path_sum[i*w+j] = grid[i][j];
                else if(j==w-1) path_sum[i*w+j] = grid[i][j]+path_sum[(i+1)*w+j];
                else if(i==h-1) path_sum[i*w+j] = grid[i][j]+path_sum[i*w+j+1];
                else path_sum[i*w+j] = grid[i][j]+min(path_sum[i*w+j+1],path_sum[(i+1)*w+j]);
            }
        }
        int r = path_sum[0];
        delete[] path_sum;
        return r;
    }
};
