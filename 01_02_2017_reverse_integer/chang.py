class Solution:
    # @param {int} n the integer to be reversed
    # @return {int} the reversed integer
    def reverseInteger(self, n):
        if n is None or n == 0:
            return 0
            
        if n < 0:
            negative = -1
            n = -n
        else:
            negative = 1
        
        reversed = 0
        
        while n > 0:
            reversed = reversed * 10 + n % 10
            n = n / 10
        
        reversed = reversed * negative
        
        if reversed < -(1 << 31) or reversed > (1 << 31) - 1:
            return 0
        
        return reversed 
