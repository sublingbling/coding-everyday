class Solution {
private:
    int* dp;
    int w, h;
    int findMin(string& w1, string& w2, int m, int n){
        if(m==0) return n;
        if(n==0) return m;
        int idx = w*(n-1)+(m-1);
        if(dp[idx]!=-1) return dp[idx];
        if(w1[m-1]==w2[n-1]) return dp[idx]=findMin(w1,w2, m-1, n-1);
        return dp[idx]=1+min(min(findMin(w1,w2, m-1, n-1), findMin(w1,w2, m, n-1)), findMin(w1,w2, m-1, n));
    }
public:
    int minDistance(string word1, string word2) {
        w = word1.size();
        h = word2.size();
        int dp_size = w*h;
        dp = new int[dp_size];
        for(int i=0; i<dp_size; i++) dp[i]=-1;
        
        return findMin(word1, word2, word1.size(), word2.size());
    }
};
