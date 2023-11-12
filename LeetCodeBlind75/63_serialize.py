# 297. Serialize and Deserialize Binary Tree
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        out = []
        # Store in (val, left, right format in dfs order
        def dfs(node):
            if node == None:
                out.append('*')
                return

            out.append(str(node.val))

            out.append('l')
            dfs(node.left)

            out.append('r')
            dfs(node.right)
        
        dfs(root)
        return " ".join(out)
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        data = data.split()
        root = TreeNode()
        idx = -1

        def dfs():
            nonlocal idx
            idx += 1
            if data[idx] == '*':
                return None

            node = TreeNode()
            node.val = int(data[idx])

            # Sanity check that l and r are in data
            if data[idx + 1] == 'l':
                idx += 1
                node.left = dfs()
            if data[idx + 1] == 'r':
                idx += 1
                node.right = dfs()
            
            return node
        
        return dfs()
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
