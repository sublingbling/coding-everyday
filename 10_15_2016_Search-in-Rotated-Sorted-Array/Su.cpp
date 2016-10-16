// Solution O(n)
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

// Solution O(logn)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int last = nums.size()-1;
        int first = 0;
        while(first<last){
            int mid=(last+first)/2;
            if(nums[mid]>nums[last]) first=mid+1;
            else last=mid;
        }
        int min=last;
        
        last = nums.size()-1;
        first = 0;
        while(first<=last){
            int mid=(last+first)/2;
            int realmid = (mid+min)%nums.size();
            if(nums[realmid]==target) return realmid;
            if(nums[realmid]<target) first=mid+1;
            else last=mid-1;
        }
        return -1;
    }
};
