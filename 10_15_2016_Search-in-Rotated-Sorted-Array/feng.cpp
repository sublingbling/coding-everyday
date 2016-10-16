class Solution {
public:
    //search in rotated array, it can always been devided to two parts, rotated and sorted from the middle point
    int search_r(vector<int>& nums, int l, int r, int target){
        if(l>r) return -1;
        int mid = (l+r)/2;
        if(nums[mid]==target) return mid;
        
        if(nums[l] < nums[mid]){
            if((target<= nums[mid-1]) && (target >= nums[l])) return search_b(nums,l,mid-1,target);
            else return search_r(nums,mid+1,r,target);
        }
        else{
            if((nums[mid+1] <= target) && (target <= nums[r])) return search_b(nums,mid+1,r,target);
            else return  search_r(nums,l,mid-1,target);
        }
    }
    
    //search in sorted array
    int search_b(vector<int>& nums, int l, int r, int target){
        if(l>r) return -1;
        int mid = (l+r)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]>target) return search_b(nums,l,mid-1,target);
        else return search_b(nums,mid+1,r,target);
    }
    int search(vector<int>& nums, int target) {
        return search_r(nums, 0, nums.size()-1, target);
    }
};
