class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != '0') {
                    DFSFloodIsland(i, j, grid);
                    result++;
                }
            }
        }
        return result;
        
    }
    // Start from i,j corner of an island, use dfs to traversal the island and flood them with water during traversal
    void DFSFloodIsland(int seed_i, int seed_j, vector<vector<char>>& grid){
        std::stack<std::pair<int, int> > wave_front;
        wave_front.push(std::pair<int, int>(seed_i, seed_j));
        while(!wave_front.empty()){
            std::pair<int, int> sprite = wave_front.top();
            wave_front.pop();
            int i = sprite.first; int j = sprite.second; 
            //Flooded.
            grid[i][j] = '0';
            //Check as much as four connected cells and expand the flood's wave front if it is island
            if (i > 0 && grid[i-1][j] == '1') {
                wave_front.push(std::pair<int, int>(i-1, j));
            }
            if (i < grid.size()-1 && grid[i+1][j] == '1') {
                wave_front.push(std::pair<int, int>(i+1, j));
            }
            if (j > 0 && grid[i][j-1] == '1') {
                wave_front.push(std::pair<int, int>(i, j-1));
            }
            if (j < grid[0].size()-1 && grid[i][j+1] == '1') {
                wave_front.push(std::pair<int, int>(i, j+1));
            }
        }
    }
};
