# 104. Maximum Depth of Binary Tree
def maxDepth(self, root: Optional[TreeNode]) -> int:
    def dfs(node, depth):
        if node == None:
            return depth
        
        return max(dfs(node.left, depth + 1), dfs(node.right, depth + 1))
    
    return dfs(root, 0)
