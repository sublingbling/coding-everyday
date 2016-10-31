class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if (0==size) return 0;
        
        int max = nums[0];
        int i = 0;
        for (i=0; i<size; i++)
        {
            if (nums[i] > max) max = nums[i];
            if (nums[i] > 0) break;
        }
        if (size==i) return max;
        
        int sum = 0;
        max = 0;
        for (; i<size; i++)
        {
            sum += nums[i];
            if (sum > max) max = sum;
            if (sum < 0) sum = 0;
        }
        return max;
    }
};
