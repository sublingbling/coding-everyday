class Solution:
# @return a list of lists of integers
def generate(self, numRows):
    lists = []
    for i in range(numRows):
        lists.append([1]*(i+1))
        if i>1 :
            for j in range(1,i):
                lists[i][j]=lists[i-1][j-1]+lists[i-1][j]
    return lists
