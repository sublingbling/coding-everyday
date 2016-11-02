class Solution {
public:
    unordered_map<int, int> mymap;
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> ret;
        if (0==size) return ret;
        
        for (int i=0; i<size; i++)
        {
            if (mymap.find(target-nums[i]) != mymap.end())
            {
                ret.push_back(mymap[target-nums[i]]);
                ret.push_back(i);
                return ret;
            }
            else
            {
                mymap.emplace(nums[i],i);
            }
        }
        
        return ret;
    }
};
