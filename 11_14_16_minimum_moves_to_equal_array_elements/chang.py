class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        minNum = min(nums)
        count = 0
        for num in nums:
            count = count + num - minNum
        return count
