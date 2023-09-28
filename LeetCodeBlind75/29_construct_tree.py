# 105. Construct Binary Tree from Preorder and Inorder Traversal
def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
    inorderMap = {}
    for i in range(len(preorder)):
        inorderMap[inorder[i]] = i
    
    preIdx = 0
    def construct(lBound, rBound):
        nonlocal preIdx
        # Check if node is leaf
        if lBound > rBound:
            return None

        node = TreeNode(preorder[preIdx])
        inIdx = inorderMap[preorder[preIdx]]
        preIdx += 1

        node.left = construct(lBound, inIdx - 1)
        node.right = construct(inIdx + 1, rBound)

        return node
    
    root = construct(0, len(inorder) - 1)
    return root
