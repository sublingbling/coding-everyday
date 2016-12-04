class Solution {
private:
    //o(n) solution
    int findKthLargest(vector<int>& nums, int l, int r, int k){
        int fast=l, slow=l;
        //choose a random key ans swap to the end, random will have better average performance.
        int key = l + rand()%(r-l+1);
        int t=nums[key];
        nums[key]=nums[r];
        nums[r]=t;
        //split 
        for(;fast<r; fast++){
            if(nums[fast]<nums[r]){
                int t=nums[fast];
                nums[fast]=nums[slow];
                nums[slow]=t;
                slow++;
            }
        }
        //swap key to the middle
        t=nums[r];
        nums[r]=nums[slow];
        nums[slow]=t;
        
        //hit with this key
        if(r-slow==k-1) return t;
        //search left part
        else if(r-slow<k-1) return findKthLargest(nums, l, slow-1, k-1-r+slow);
        //search right part
        else return findKthLargest(nums, slow+1, r, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        return findKthLargest(nums, 0, nums.size()-1, k);
        
    }
};
