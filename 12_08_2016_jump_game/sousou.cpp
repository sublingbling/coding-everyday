class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (1==nums.size()) return true;
        else if (0==nums[0]) return false;
        
        for (int i=nums.size()-2; i>=0; i--)
        {
            if (0 == nums[i])
            {
                int count = 1;
                for (i=i-1; i>0; i--,count++)
                {
                    if (nums[i] > count)
                        break;
                }
                if (0==i && nums[0]<=count) return false;
            }
        }
        return true;
    }
};
