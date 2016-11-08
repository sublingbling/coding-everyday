class Solution:
    # @param {int[]} nums an integer array
    # @return nothing, do this in-place
    def moveZeroes(self, nums):
        if nums is None or len(nums) == 0:
            return 
        #insert position pointer
        insertPos = 0
        
        for num in nums:
            if num != 0:
                nums[insertPos] = num
                insertPos += 1
            
        while insertPos != len(nums):
            nums[insertPos] = 0
            insertPos += 1
            
        return 
