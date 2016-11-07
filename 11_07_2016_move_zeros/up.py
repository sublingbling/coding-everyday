class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        ptr , numZ= 0, 0
        for i in xrange(len(nums)):
            if nums[i] :
                # not zero
                if i != ptr:
                    nums[ptr] = nums[i]
                    
                ptr += 1
            else:
                # zero
                numZ += 1
                
        for i in xrange(len(nums)-numZ,len(nums)):
            nums[i] = 0
