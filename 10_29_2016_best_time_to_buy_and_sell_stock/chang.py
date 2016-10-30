class Solution:
    """
    @param prices: Given an integer array
    @return: Maximum profit
    """
    def maxProfit(self, prices):
        # write your code here
        total = 0
        low, high = sys.maxint, 0
        for x in prices:
            if x - low > total:
                total = x - low
            if x < low:
                low = x
        return total
