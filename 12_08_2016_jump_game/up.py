class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if not nums:
            return False
        
        n = len(nums)
        if n== 1:
            return True
        last = n -1
        #detect from the end
        
        for i in reversed(range(n-1)):
            if nums[i] + i >= last:
                last = i
        
        if last > 0 :
            return False
        else:
            return True
