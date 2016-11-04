class Solution:
    # @param {TreeNode} root the root of the binary tree
    # @return {List[str]} all root-to-leaf paths
    def binaryTreePaths(self, root):
        result = []
        path = []
        if root is None:
            return []
        self.dfs(path, result, root)
        return result
        
        
    def dfs(self, path, result, node):
        path.append(str(node.val))
        
        if node.left is None and node.right is None:
            result.append("->".join(path))
            path.pop()
            return
        
        if node.left:
            self.dfs(path, result, node.left)
        if node.right:
            self.dfs(path, result, node.right)
        
        path.pop()
            
   
