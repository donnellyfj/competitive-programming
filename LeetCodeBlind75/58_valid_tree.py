# 261. Graph Valid Tree
from typing import List
from collections import defaultdict
def valid_tree(self, n: int, edges: List[List[int]]) -> bool:
    # write your code here
    # Build adj list
    adj = defaultdict(lambda: [])
    taken = {}
    for s, t in edges:
        adj[s].append(t)
        adj[t].append(s)

    seen = [0] * n
    def dfs(node):
        # Check for cycle - return true if no cycle
        if seen[node]:
            return False
        seen[node] = 1
        out = True
        for neighbor in adj[node]:
            if (node, neighbor) in taken or (neighbor, node) in taken:
                continue
            taken[(node, neighbor)] = True
            out &= dfs(neighbor)

        return out
    
    # Start dfs on any node
    out = dfs(0)

    # Check that all nodes were visited
    return sum(seen) == n and out
