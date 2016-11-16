class Solution {
private:
void flood(vector<vector<int>>& m, int x, int y, int n){
    int w = m[0].size();
    int h = m.size();
    if(x<0 || x>=w || y<0 || y>= h || m[y][x]!=-1) return;
    m[y][x] = n;
    flood(m,x-1,y,n);
    flood(m,x+1,y,n);
    flood(m,x,y-1,n);
    flood(m,x,y+1,n);
}
public:
    //each time, flood '1' with a count; O(n)
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        
        vector<vector<int>> m;
        for(int i=0; i<grid.size();i++){
            vector<int> row;
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1') row.push_back(-1);
                else row.push_back(0);
            }
            m.push_back(row);
        }
        
        int count=1;
        for(int i=0; i<m.size();i++){
            for(int j=0; j<m[0].size(); j++){
                if(m[i][j]==-1){
                    flood(m,j,i,count);
                    count++;
                }
            }
        }
        return count-1;
    }
};
