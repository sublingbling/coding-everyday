class Solution(object):
    def binarySearch(self, nums, target):
        """
        : type nums: List[int]
        : type target: float
        : rtype: int 
        """
        # typical binary search 
        lo = 0
        hi = len(nums) - 1
        while lo < hi:
            mid = (lo + hi) / 2
            if target < nums[mid]:
                hi = mid
            else:
                lo = mid + 1
        return lo
                    
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # this problem could be sloved like this,
        # find the insert index of target - 0.1 and target + 0.1
        # so we need a binary search function. 
        # this binary search function should return the index where the target should be inserted 
        # create the binarySearch function above
        
        # calculate left edge and right edge of target
        leftEdge = self.binarySearch(nums, target - 0.1)
        rightEdge = self.binarySearch(nums, target + 0.1) 
        
        # check if the target is between the edges
        if target == nums[leftEdge] :
            # here's AAAA BIG HEADACHE! 
            # if the target is at the end, the rightEdge is correct and no need to minus 1...
            if target != nums[-1]:
                rightEdge -= 1
        else:
            # target doesn't exist
            return [-1, -1]
        
        return [leftEdge, rightEdge]
