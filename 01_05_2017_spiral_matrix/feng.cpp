class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //l,t -> r,t;  t++; 
        // -> r,b; r--;
        // -> l,b; b--;
        // -> l,t; l++;
        vector<int> ret;
        if(matrix.empty()) return ret;
        int l = 0 , r = matrix[0].size()-1, t =0, b = matrix.size()-1;
        while(l<=r && t<=b){
            for(int i=l; i<= r; i++) ret.push_back(matrix[t][i]);
            t++;
            if(t>b) break;
            for(int i=t; i<=b; i++) ret.push_back(matrix[i][r]);
            r--;
            if(l>r) break;
            for(int i=r; i>= l; i--) ret.push_back(matrix[b][i]);
            b--;
            if(t>b) break;
            for(int i=b; i>= t; i--) ret.push_back(matrix[i][l]);
            l++;
        }
        return ret;
    }
};
