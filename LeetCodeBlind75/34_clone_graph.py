# 133. Clone Graph
from typing import Optional
from collections import defaultdict
def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
    # First, create copies of each node and build adjacency list
    adj = defaultdict(lambda: [])
    copies = {}
    def dfs(node):
        if node == None or node.val in copies:
            return
        
        copies[node.val] = Node(node.val)
        for neighbor in node.neighbors:
            adj[node.val].append(neighbor.val)
            dfs(neighbor)
    
    dfs(node)

    # Build graph
    for copy in copies.values():
        for neighbor in adj[copy.val]:
            copy.neighbors.append(copies[neighbor])

    if node != None:
        return copies[node.val]
    else:
        return None
