# 200. Number of Islands
from typing import List
def numIslands(self, grid: List[List[str]]) -> int:
    def dfs(row, col):
        if grid[row][col] != '1':
            return
        
        # Mark coordinate as seen
        grid[row][col] = 'X'

        # Try up
        if row > 0:
            dfs(row - 1, col)
        # Try down
        if row < len(grid) - 1:
            dfs(row + 1, col)
        # Try left
        if col > 0:
            dfs(row, col - 1)
        # Try right
        if col < len(grid[0]) - 1:
            dfs(row, col + 1)
    
    islands = 0
    for row in range(len(grid)):
        for col in range(len(grid[0])):
            if grid[row][col] == '1':
                dfs(row, col)
                islands += 1
    
    return islands
