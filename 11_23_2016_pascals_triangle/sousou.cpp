class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> tri;
        if (0==numRows) return tri;
        
        vector<int> row0;
        row0.push_back(1);
        tri.push_back(row0);
        
        for (int i=1; i<numRows; i++)
        {
            vector<int> lastrow = tri[i-1];
            vector<int> row;
            row.push_back(1);
            for (int j=0; j<lastrow.size()-1; j++)
            {
                row.push_back(lastrow[j]+lastrow[j+1]);
            }
            row.push_back(1);
            tri.push_back(row);
        }
        
        return tri;
        
    }
};
