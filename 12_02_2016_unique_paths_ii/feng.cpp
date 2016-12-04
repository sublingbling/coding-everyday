class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int w = obstacleGrid[0].size();
        int h = obstacleGrid.size();
        int* state = new int[w*h];
        for(int i= h-1; i>=0; i--){
            for(int j=w-1; j>=0; j--){
                if(obstacleGrid[i][j]==1) state[i*w+j]=0;
                else if(j==w-1&&i==h-1) state[i*w+j]= 1;
                else if(j==w-1) state[i*w+j]= state[(i+1)*w+j];
                else if(i==h-1) state[i*w+j]= state[i*w+j+1];
                else state[i*w+j] = state[(i+1)*w+j] + state[i*w+j+1];
            }
        }
        int result = state[0];
        delete[] state;
        return result;
        
    }
};
