# 62. Unique Paths
def uniquePaths(self, m: int, n: int) -> int:
    # Intuition: Construct a grid, with the far right column and bottom row as all 1s
    #            Then, each cell should be the sum of its right neighbor and bottom neighbor.
    #            Return the top left cell of this grid.
    # Example: 6 3 1
    #          3 2 1
    #          1 1 1

    # Construct empty grid
    grid = []
    for i in range(m):
        grid.append([0] * n)
    
    # Fill in bottom row and right column with 1s
    for row in range(m):
        grid[row][-1] = 1
    for col in range(n):
        grid[-1][col] = 1
    
    # Compute sums
    for row in reversed(range(m - 1)):
        for col in reversed(range(n - 1)):
            grid[row][col] = grid[row + 1][col] + grid[row][col + 1]

    return grid[0][0]
