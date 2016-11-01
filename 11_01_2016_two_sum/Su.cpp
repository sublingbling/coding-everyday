class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> idx(2,0);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    idx[0]=i;
                    idx[1]=j;
                    return idx;
                }
            }
        }
        return idx;
    }
};
