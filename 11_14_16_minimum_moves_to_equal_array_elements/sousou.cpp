class Solution {
public:
    int minMoves(vector<int>& nums) {
        int size = nums.size();
        if (0==size) return 0;
        
        int min = nums[0];
        for (int i=1; i<size; i++)
        {
            if (nums[i] < min)
            {
                min = nums[i];
            }
        }
        
        unsigned int count = 0;
        for (int i=0; i<size; i++)
        {
            count += nums[i] - min;
        }
        
        return count;
    }
};
