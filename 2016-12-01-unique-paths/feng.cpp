class Solution {
private:
    int *state;
    int uniquePaths(int m, int n, int i, int j){
        if(i==m-1) return 1;
        if(j==n-1) return 1;
        if(state[i*n + j] != -1) return state[i*n+j];
        state[i*n+j]= uniquePaths(m,n,i+1,j)+uniquePaths(m,n,i,j+1);
        return state[i*n+j];
    }
public:
    int uniquePaths(int m, int n) {
        state = new int[m*n];
        for(int i=0; i<m*n; i++) state[i]=-1;
        int result= uniquePaths(m,n,0,0);
        delete[] state;
        return result;
    }
};
