class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if (sz < 1) {
            return sz;
        }
        int prev = 0, curr = 1;
        while (curr < sz) {
            if (nums[curr] > nums[prev]) {
                nums[prev+1] = nums[curr];
                prev++;
            }
            curr++;
        }
        return prev+1;
    }
};
