class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int as = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) nums[as++]=nums[i];
        }
        while(as<nums.size()) nums[as++]=0;
    }
};
