# 48. Rotate Image
from typing import List
def rotate(self, matrix: List[List[int]]) -> None:
    """
    Do not return anything, modify matrix in-place instead.
    """
    n = len(matrix)
    # Moving outside to inside, spiral values clockwise one by one
    for i in range(n):
        for j in range(i, n - i - 1):
            # Rotate values
            curr = matrix[i][j]
            nxt = matrix[j][n - i - 1]
            matrix[j][n - i - 1] = curr

            curr = nxt
            nxt = matrix[n - i - 1][n - j - 1]
            matrix[n - i - 1][n - j - 1] = curr

            curr = nxt
            nxt = matrix[n - j - 1][i]
            matrix[n - j - 1][i] = curr

            curr = nxt
            matrix[i][j] = curr
