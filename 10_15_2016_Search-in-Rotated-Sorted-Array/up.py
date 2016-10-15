class Solution(object):
    
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # logN, like binary search. But here we need 2 points to determine which half the target is.
        # THe 2 points should be the first item, the middle item and the last item.
        
        # check empty
        if not nums :
            return -1
        
        # we need the length value to get the middle point 
        n = len(nums)
        middle = nums[n/2]
        front = nums[0]
        
        # check if the target is one of these 2 points
        if target == middle :
            return n/2
        elif target == front :
            return 0
        
        # let's guess where's the target, 1st half or 2nd half? First suppose it's the first half.
        firstHalf = 1
        
        # two situations here, one is front < middle , the other is front > middle 
        if front < middle:
            # just focus on the 2nd half case, we already assume it's in the first half
            # now front < middle, min/max point is in the 2nd half
            # if target > middle , the target is in 2nd half
            # if target < middle and target > front, the target is in the 1st half
            # if targe < middle and target < front , the target is in the 2nd half
            if target > middle :
                firstHalf = 0
            elif target < front :
                firstHalf = 0
        else:
            # now front > middle, min/max point is in the 1st half
            # if target < middle, target is in 1st half
            # if target > middle and target > front, target is in 1st half
            # if target > middle and target < front, target is in 2nd half
            if target > middle and target < front:
                firstHalf = 0
        # above logic could be simplified
        
        if firstHalf:
            return self.search(nums[:n/2],target)
        else:
            idx = self.search(nums[n/2:], target)
            if idx == -1:
                return idx
            else :
                return n/2 + idx
        # above logic could also be simplified
        
