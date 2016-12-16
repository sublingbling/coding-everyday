class Solution {
    vector<vector<bool>> LUT;
    vector<int> DP;
    void buildLUT(string& s) {
        int sz = s.size();
        LUT = vector<vector<bool>>(sz, vector<bool>(sz, false));
        for (int i = 0; i < sz; i++) {
            LUT[i][i] = true;
            for (int j = 1; i-j >= 0 && i+j-1 < sz; j++) {
                if (i+j < sz) {
                    LUT[i-j][i+j] = (s[i-j] == s[i+j]) && LUT[i-j+1][i+j-1];
                }
                LUT[i-j][i+j-1] = (s[i-j] == s[i+j-1]) && (j > 1 ? LUT[i-j+1][i+j-2] : true);
            }
        }
    }
public:
    int minCut(string s) {
        int sz = s.size();
        if (sz <= 1) {
            return 0;
        }
        buildLUT(s);
        DP.resize(sz+1);
        DP[sz] = -1;
        DP[sz-1] = 0;
        for (int i = sz-2; i >= 0; i--) {
            DP[i] = sz-i-1;
            for (int j = 0; i+j < sz; j++) {
                if (LUT[i][i+j]) {
                    DP[i] = min(DP[i], 1 + DP[i+j+1]);
                }
            }
        }
        return DP[0];
    }
};
