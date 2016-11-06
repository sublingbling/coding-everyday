class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        int length = 1;
        for(int i=1; i<nums.size();i++){
            if(nums[length-1]!=nums[i]){
                nums[length]=nums[i];
                length++;
            } 
        }
        return length;
    }
};
