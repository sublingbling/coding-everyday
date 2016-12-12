class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        if not nums:
            return 0
        
        # not null
        n = len(nums)
        seq = [1] * n
        
        for i in range(n):
            for j in range(i):
                if nums[i] > nums[j]:
                    seq[i] = max(seq[i], seq[j] + 1);
        
        return max(seq)
        
