class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int i=0;
        while (0 != nums[i])
            i++;
        int j = i;
        while (i < size)
        {
            if (0!=nums[i] && 0==nums[j])
            {
                nums[j] = nums[i];
                nums[i] = 0;
            }
            if (0 == nums[i]) i++;
            if (0 != nums[j]) j++;
        }
    }
};
