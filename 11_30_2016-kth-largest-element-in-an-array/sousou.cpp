class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        if (0==size) return 0;
        
        sort(nums.begin(), nums.end());
        return nums[size -k];
    }
};
