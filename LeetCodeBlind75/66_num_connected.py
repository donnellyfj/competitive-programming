# 323. Number of Connected Components in an Undirected Graph
from typing import List
from collections import defaultdict
def count_components(self, n: int, edges: List[List[int]]) -> int:
    # write your code here
    seen = [0] * n
    # Build adj list
    adj = defaultdict(lambda: [])
    for s, t in edges:
        adj[s].append(t)
        adj[t].append(s)

    def dfs(node, color):
        # Traverse through as many nodes as you can and mark them
        seen[node] = color
        for neighbor in adj[node]:
            if seen[neighbor] == 0:
                dfs(neighbor, color)

    color = 1
    node = 0
    while node < n:
        # Find first node that hasn't been seen
        while node < n and seen[node] != 0:
            node += 1
        if node >= n:
            break
        dfs(node, color)
        color += 1

    return color - 1
