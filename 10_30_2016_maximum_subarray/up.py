class Solution(object):
    
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        if not nums:
            return 0
        
        n = len(nums)
        if n == 1:
            return nums[0]
            
        # DP question, need a array of max sum
        maxSumDP = [0] * n 
        maxSumDP[0] = maxSub = nums[0]
        
        
        # start DP
        for i in xrange(1,n):
            maxSumDP[i] = max(maxSumDP[i-1] + nums[i], nums[i])
            maxSub = max(maxSumDP[i], maxSub)
        
        return maxSub
