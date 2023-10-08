# Kth Smallest Element in a BST
def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
    out = []
    def dfs(node):
        if node == None or len(out) == k:
            return
        dfs(node.left)
        if len(out) < k:
            out.append(node.val)
        dfs(node.right)
    
    dfs(root)
    return out[-1]
