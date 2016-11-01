class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sorted(nums);
        std::sort(sorted.begin(), sorted.end());
        int l = 0, r = nums.size() - 1;
        vector<int> res;
        while (l < r) {
            int sum = sorted[l] + sorted[r];
            if (sum < target) {
                l++;
            } else if (sum > target) {
                r--;
            } else {
                int idxLeft = std::find(nums.begin(), nums.end(), sorted[l]) - nums.begin();
                int idxRight = std::find(nums.begin(), nums.end(), sorted[r]) - nums.begin();;
                while (idxRight == idxLeft) {
                   idxRight = std::find(nums.begin() + idxRight + 1, nums.end(), sorted[r]) - nums.begin();
                }
                res.push_back(idxLeft);
                res.push_back(idxRight);
                return res;
            }
        }
        return res;
    }
};
