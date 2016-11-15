class Solution {
public:
    //same as -1 for one element each time
    int minMoves(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int _min=nums[0],_sum=0;
        for(auto a:nums){
            _min=min(a,_min);
            _sum+=a;
        }
        return _sum-_min*nums.size();
        
    }
};
