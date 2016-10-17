class Solution {
public:
    
    int search(vector<int>& nums, int l, int r, int target){
        if(l>r) return -1;
        int mid = (l+r)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) return search(nums, mid+1,r,target);
        else return search(nums,l, mid-1,target);
    }
    
    int search_l(vector<int>& nums, int l, int r, int target){
         if(l>r) return -1;
        int mid = (l+r)/2;
        if(nums[mid]==target){
             int t = search_l(nums, l,mid-1,target);
             if(t==-1) return mid;
             else return t;
        }
        else if(nums[mid]<target) return search_l(nums,mid+1,r,target);
        else return search_l(nums,l, mid-1, target);
    }
    
    int search_r(vector<int>& nums, int l, int r, int target){
        if(l>r) return -1;
        int mid = (l+r)/2;
        if(nums[mid]==target){
             int t = search_r(nums, mid+1,r,target);
             if(t==-1) return mid;
             else return t;
        }
        else if(nums[mid]<target) return search_r(nums,mid+1,r,target);
        else return search_r(nums,l, mid-1, target);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result_v(2,-1);
        
        int result = search(nums,0,nums.size()-1,target);
        if(result == -1) return result_v;
        
        int result_l = search_l(nums, 0, result-1, target);
        if(result_l == -1) result_v[0] = result;
        else result_v[0]=result_l;
        
        int result_r = search_r(nums, result+1, nums.size()-1, target);
        if(result_r == -1) result_v[1] = result;
        else result_v[1]= result_r;
        
        return result_v;
    }
};
