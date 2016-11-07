class Solution:
    """
    @param A: a list of integers
    @return an integer
    """
    def removeDuplicates(self, A):
        # write your code here
        if A == []:
            return 0
        count = 0
        for i in range(0, len(A)):
            if A[i] == A[i-1]:
                continue
            else:
                A[count] = A[i]
                count += 1
        return count
          
