class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        ptrRed = i = 0
        ptrBlue = n - 1
        
        while i <= ptrBlue:
            if nums[i] == 0:
                nums[i], nums[ptrRed] = nums[ptrRed], 0
                i += 1
                ptrRed += 1
            elif nums[i] == 2:
                nums[i], nums[ptrBlue] = nums[ptrBlue], 2
                ptrBlue -= 1
            else :
                i += 1
