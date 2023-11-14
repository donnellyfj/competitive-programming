# 417. Pacific Atlantic Water Flow
from typing import List
def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
    rMax = len(heights)
    cMax = len(heights[0])
    vals = []
    for r in range(rMax):
        vals.append([0] * cMax)
    out = []
    
    # ocean -> 1 = Pacific, 2 = Atlantic
    def dfs(r, c, ocean):
        # Check if cell has been visited
        if (vals[r][c] | ocean) == vals[r][c]:
            return
        vals[r][c] |= ocean
        if vals[r][c] == 3:
            out.append([r, c])
        # Go to adjacent uphill values
        if r < rMax - 1:
            if heights[r + 1][c] >= heights[r][c]:
                dfs(r + 1, c, ocean)
        if r > 0:
            if heights[r - 1][c] >= heights[r][c]:
                dfs(r - 1, c, ocean)
        if c < cMax - 1:
            if heights[r][c + 1] >= heights[r][c]:
                dfs(r, c + 1, ocean)
        if c > 0:
            if heights[r][c - 1] >= heights[r][c]:
                dfs(r, c - 1, ocean)
    
    for i in range(rMax):
        # Left side
        dfs(i, 0, 1)
        # Right side
        dfs(i, cMax - 1, 2)

    for i in range(cMax):
        # Top side
        dfs(0, i, 1)
        # Bottom side
        dfs(rMax - 1, i, 2)

    return out
