class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lastIndex = nums.size()-1;
        int firstIndex = 0;
        
        while(target>nums[firstIndex] && nums[firstIndex]<nums[firstIndex+1]) firstIndex++;
        if(target==nums[firstIndex]) return firstIndex;
        
        while(target<nums[lastIndex] && nums[lastIndex]>nums[lastIndex-1]) lastIndex--;
        if(target==nums[lastIndex]) return lastIndex;
        
        return -1;
    }
};
