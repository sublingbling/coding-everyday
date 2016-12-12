class Solution {
    vector<vector<int>> DP;
    int _helper(vector<int>& nums, int start, int lb) {
        //cout << start << " " << lb << endl;
        if (lb > 0 && DP[start][lb] != -1) {
            return DP[start][lb];
        }
        int lbVal = (lb > 0 ? nums[lb-1] : INT_MIN);
        if (start == nums.size()-1) {
            DP[start][lb] = nums[start] > lbVal ? 1 : 0;
            
        } else if (nums[start] <= lbVal) {
            DP[start][lb] = _helper(nums, start+1, lb);
        } else {
            DP[start][lb] = max(_helper(nums, start+1, lb), 1+_helper(nums, start+1, start+1));
        }
        return DP[start][lb];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) {
            return 0;
        }
        DP = vector<vector<int>>(sz, vector<int>(sz+1, -1));
        for (int i = 0; i < sz; i++) {
            _helper(nums, i, 0);
        }
        int res = 0;
        for (auto& v : DP) {
            for (auto& u : v) {
                res = max(res, u);
            }
        }
        return res;
     }
};
