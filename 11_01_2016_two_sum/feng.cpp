class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> r;
        if(nums.size()<2) return r;
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            if(m.find(target-nums[i])!=m.end()){
                r.push_back(m[target-nums[i]]);
                r.push_back(i);
                return r;
            }
            m.insert({nums[i],i});
        }
        return r;
    }
};
