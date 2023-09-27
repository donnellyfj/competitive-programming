# 100. Same Tree
def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
    def dfs(node1, node2):
        if node1 == node2 == None:
            return True
        elif node1 == None or node2 == None:
            return False
        
        return dfs(node1.left, node2.left) and dfs(node1.right, node2.right) and node1.val == node2.val
    
    return dfs(p, q)
