class Solution:
    # @param s, a string
    # @return a list of lists of string
    def partition(self, s):
        res = []
        self.dfs(s, [], res)
        return res
    
    def dfs(self, s, path, res):
        if not s:
            res.append(path[:])
            #return
        for i in range(1, len(s) + 1):
            if self.isPal(s[:i]):
                path.append(s[:i])
                self.dfs(s[i:], path, res)
                path.pop()
    
    def isPal(self, s):
        for i in range(len(s)):
            if s[i] != s[len(s) - i -1]:
                return False
        return True
