class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length=0;
        for(int i=0;i<nums.size();i++){
            if(i==0 || nums[i]!=nums[i-1]) nums[length++]=nums[i];
        }
        return length;
    }
};
