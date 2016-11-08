class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int sz = nums.size();
        for (int j = 0; j < sz; j++) {
            if (nums[j] != 0) {
                std::swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};
