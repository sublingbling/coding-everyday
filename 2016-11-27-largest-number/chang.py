class Solution:	
    # @param num: A list of non negative integers
    # @return: A string
    def largestNumber(self, num):
        nums = sorted(num, cmp=lambda x, y: 1 if str(x) + str(y) < str(y) + str(x) else -1)
        largest = ''.join([str(x) for x in nums])
        i, length = 0, len(largest)
        while i + 1 < length:
            if largest[i] != '0':
                break
            i += 1
        return largest[i:]
