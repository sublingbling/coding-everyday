class Solution {
public:
    //counting sort
    void sortColors(vector<int>& nums) {
        int color[3]={0};
        for(auto a:nums) color[a]++;
        int idx=0;
        while(idx<color[0])          {nums[idx]=0; idx++;}
        while(idx<color[0]+color[1]) {nums[idx]=1; idx++;}
        while(idx<nums.size())       {nums[idx]=2; idx++;}
    }
};
