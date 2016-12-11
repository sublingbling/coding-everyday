class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        n = len(nums)
        start, end, jump = 0, 0, 0
        
        while end < n - 1:
            # not the end
            jump += 1
            newEnd = end + 1
            
            # find new end
            for i in range(start, end + 1):
                if i + nums[i] >= n - 1:
                    return jump
                newEnd = max(newEnd, i + nums[i])
                
            start = end + 1
            end = newEnd
        
        return jump
        
