class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n_0, n_1, n_2;
        n_0 = 0; n_1 = 0; n_2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            nums[i] == 0 ? n_0++ : (nums[i] == 1 ? n_1++:n_2++);
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = i < n_0 ? 0 : (i < n_1 + n_0 ? 1 : 2);
        }
    }
};
