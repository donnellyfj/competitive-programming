# 572. Subtree of Another Tree
def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
    def dfs(node):
        def check(node, subNode):
            if node == None or subNode == None:
                return node == subNode
            if node.val != subNode.val:
                return False
            return check(node.left, subNode.left) and check(node.right, subNode.right)
        
        if node == None:
            return False
        # At each node, if the value equals the subRoot value, check the subtree
        # This is a similar idea to using a trie to search for a string
        out = False
        if node.val == subRoot.val:
            out = check(node, subRoot)
        
        return out or dfs(node.left) or dfs(node.right)
    
    return dfs(root)
