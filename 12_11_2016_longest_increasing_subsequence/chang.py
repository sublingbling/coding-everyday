class Solution:
    """
    @param nums: The integer array
    @return: The length of LIS (longest increasing subsequence)
    """
    def longestIncreasingSubsequence(self, nums):
        if nums is None or len(nums) == 0:
            return 0
        dp = [1] * len(nums)
        
        for i in xrange(len(nums)):
            for j in xrange(i):
                if nums[i] > nums[j]:
                    if dp[i] <= dp[j] + 1:
                        dp[i] = dp[j] +1
        
        return max(dp)
