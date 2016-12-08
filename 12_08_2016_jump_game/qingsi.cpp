class Solution {
    bool canJumpHelper(vector<int>& nums, int startIdx) {
        int sz = nums.size();
        if (nums[startIdx] >= sz-1-startIdx)
            return true;
        else {
            int nextIdx = startIdx;
            int maxStep = nums[startIdx];
            for (int i = 1; i <= nums[startIdx]; i++) {
                if (nums[startIdx+i] + i > maxStep) {
                    nextIdx = startIdx + i;
                    maxStep = nums[startIdx+i] + i;
                }
            }
            if (nextIdx == startIdx)
                return false;
            else
                return canJumpHelper(nums, nextIdx);
        }
    }
public:
    bool canJump(vector<int>& nums) {
        return canJumpHelper(nums, 0);
    }
};
