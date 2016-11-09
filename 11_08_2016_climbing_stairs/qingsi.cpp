class Solution {
    void _climbStairsHelper(vector<int>& DP, int n) {
        if (DP[n] > 0) {
            return;
        }
        if (n < 2) {
            DP[n] = 1;
        } else {
            _climbStairsHelper(DP, n-1);
            _climbStairsHelper(DP, n-2);
            DP[n] = DP[n-1] + DP[n-2];
        }
    }
public:
    int climbStairsRecursive(int n) {
        vector<int> DP(n+1, -1);
        _climbStairsHelper(DP, n);
        return DP[n];
    }
    
    int climbStairs(int n) {
        vector<int> DP(n+1, -1);
        for (int i = 0; i <= n; i++) {
            if (i < 2) {
                DP[i] = 1;
            } else {
                DP[i] = DP[i-1] + DP[i-2];
            }
        }
        return DP[n];
    }
};
