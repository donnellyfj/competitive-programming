# 54. Spiral Matrix
from typing import List
def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
    dirMap = {0: [0, 1], 1: [1, 0], 2: [0, -1], 3: [-1, 0]}
    direction = 0
    seen = {}
    out = []
    count = 0
    row = col = 0
    m = len(matrix)
    n = len(matrix[0])

    # Loop through all indices in matrix
    while count < m * n:
        # Add current index to out
        out.append(matrix[row][col])
        seen[(row, col)] = 1
        count += 1

        # Get next coords
        nextRow = row + dirMap[direction][0]
        nextCol = col + dirMap[direction][1]

        # Check if we need to change direction
        if nextRow >= m or nextRow < 0 or nextCol >= n or nextCol < 0 or (nextRow, nextCol) in seen:
            direction = (direction + 1) % 4
            nextRow = row + dirMap[direction][0]
            nextCol = col + dirMap[direction][1]

        row = nextRow
        col = nextCol
    
    return out
