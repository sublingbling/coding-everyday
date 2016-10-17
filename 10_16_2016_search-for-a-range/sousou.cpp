class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range(2, -1);
        int numsSize = nums.size();
        if (0==numsSize) return range;
    
        // find a match first
        int low=0, high=numsSize-1,mid=(low+high)/2;
        while(low < high)
        {
            if (target == nums[mid]) break;
            if (target < nums[mid]) high = mid;
            else low = mid+1;
            mid = (low+high)/2;
        }
        
        if(target != nums[mid]) return range;
        
        // already found one match
        range[0] = mid;
        range[1] = mid;
        if (range[1]+1<numsSize && target == nums[range[1]+1])
        {
            // search right
            low = range[1];
            high = numsSize-1;
            mid = (low+high)/2;
            while (low <high)
            {
                mid = (low+high+1)/2;
                if (target == nums[mid]) low = mid;
                else high = mid-1;
            }
            if (target == nums[low]) range[1] = low;
        }
        if (range[0]-1>=0 && target == nums[range[0]-1])
        {
            // search left
            high = range[0];
            low = 0;
            while (low <high)
            {
                mid = (low+high) /2;
                if (target == nums[mid]) high = mid;
                else low = mid+1;
            }
            if (target == nums[high]) range[0] = high;
        }
        
        return range;
    }
};
