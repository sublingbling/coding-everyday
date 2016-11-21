class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        int k = 0;
        while (k <= j) {
            if (nums[k] == 0) {
                if (nums[i] != 0) {
                    swap(nums[k], nums[i]);
                } else {
                    k++;
                }
                i++;
            } else if (nums[k] == 2) {
                if (nums[j] != 2) {
                    swap(nums[k], nums[j]);
                }
                j--;
            } else {
                k++;
            }
        }
    }
};
