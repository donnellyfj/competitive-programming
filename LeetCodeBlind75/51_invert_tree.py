#  226. Invert Binary Tree
def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
    def dfs(node):
        if node == None:
            return
        
        node.left, node.right = node.right, node.left
        dfs(node.right)
        dfs(node.left)
    
    dfs(root)
    return root
