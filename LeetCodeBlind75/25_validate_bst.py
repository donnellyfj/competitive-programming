# 98. Validate Binary Search Tree
def isValidBST(self, root: Optional[TreeNode]) -> bool:
        # Inorder traversal, tree[i] should always be less than tree[i + 1]
        inorder = []
        def traverse(node):
            nonlocal inorder
            if node == None:
                return
            
            traverse(node.left)
            inorder.append(node.val)
            traverse(node.right)
        
        traverse(root)
        for i in range(len(inorder) - 1):
            if inorder[i] >= inorder[i + 1]:
                return False
        
        return True
