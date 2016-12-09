class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<2) return true;
        int max_idx = 0;
        int idx = 0;
        while(max_idx<nums.size()-1){
            max_idx = max(max_idx,idx+nums[idx]);
            if(idx == max_idx) return false;
            idx++;
        }
        return true;
    }
};
