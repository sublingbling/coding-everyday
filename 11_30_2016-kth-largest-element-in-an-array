class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        
        # get pivot
        p = nums[0]
        
        # get left mid and right based on the pivot
        l = [_ for _ in nums if _ < p]
        m = [_ for _ in nums if _ == p]
        r = [_ for _ in nums if _ > p]
        
        # l, m, r = filter(lambda x: x < p, nums), filter(lambda x: x == p, nums), filter(lambda x: x > p, nums)
        
        # get length of each set
        ll, ml, rl = len(l), len(m), len(r)
        
        if rl >= k:
            # in right set, search it in right set
            return self.findKthLargest(r,k)
        elif rl + ml >= k:
            # in equal set
            return m[0]
        else:
            # in left set
            return self.findKthLargest(l,k-ml-rl)
            
