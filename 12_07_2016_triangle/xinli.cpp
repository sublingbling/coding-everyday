    bool canJump(vector<int>& nums) {
      int max = 0;
      int i = 0;
      for (; i < nums.size() && i <= max; i++)
        max = (i + nums[i]) > max ? (i + nums[i]) : max;
      return i == nums.size();
    }
