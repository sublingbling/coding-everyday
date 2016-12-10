class Solution {
public:
    int jump(vector<int>& nums) {
        int sz = nums.size();
        int reach = 0;
        int prevReach = 0;
        int res = 0;
        for (int i = 0; i < sz-1; i++) {
            reach = max(reach, i + nums[i]);
            if (i == prevReach) {
                res++;
                prevReach = reach;
            }
        }
        return res;
    }
};
