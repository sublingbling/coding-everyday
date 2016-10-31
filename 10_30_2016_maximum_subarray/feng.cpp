class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];
        int max_acc, accum;
        accum = 0;
        max_acc = nums[0];
        for(auto a:nums){
            accum +=a;
            max_acc = max(accum,max_acc);
            accum = max(0,accum);          //if accum goes to negtive, start a new accum from 0
        }
        return max_acc;
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int max_acc, accum;
        accum = 0;
        max_acc = nums[0];
        for(auto a:nums){
            accum =a + (accum>0?accum:0); //if accum goes to negtive, start a new accum from 0
            max_acc = max(accum,max_acc);     
        }
        return max_acc;
    }
};

