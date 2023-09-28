# 102. Binary Tree Level Order Traversal
def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
    out = []
    def dfs(node, level):
        if node == None:
            return
        
        if level >= len(out):
            out.append([node.val])
        else:
            out[level].append(node.val)
        
        dfs(node.left, level + 1)
        dfs(node.right, level + 1)
    
    dfs(root, 0)

    return out
