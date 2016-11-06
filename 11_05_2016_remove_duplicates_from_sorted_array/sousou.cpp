class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (0==size) return size;

        int i=1;
        while (i<size)
        {
            if (nums[i-1] == nums[i])
            {
                nums.erase(nums.begin()+i);
                size--;
            }
            else
            {
                i++;
            }
        }
        return size;
    }
};
