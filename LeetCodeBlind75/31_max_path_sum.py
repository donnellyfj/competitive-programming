# 124. Binary Tree Maximum Path Sum
def maxPathSum(self, root: Optional[TreeNode]) -> int:
    out = root.val
    def dfs(node):
        nonlocal out
        if node == None:
            return 0
        
        left = max(0, dfs(node.left))
        right = max(0, dfs(node.right))

        out = max(out, node.val + left + right)
        return max(left, right) + node.val

    dfs(root)
    return out
