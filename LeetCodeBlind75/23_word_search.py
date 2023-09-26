# 79. Word Search
from typing import List
def exist(self, board: List[List[str]], word: str) -> bool:
    def dfs(seen, idx, row, col):
        if len(seen) == len(word):
            return True
        
        up = down = left = right = False
        
        # Try down
        if row < len(board) - 1 and (row + 1, col) not in seen and board[row + 1][col] == word[idx]:
            nextSeen = seen[:]
            nextSeen.append((row + 1, col))
            down = dfs(nextSeen, idx + 1, row + 1, col)
        
        # Try up
        if row > 0 and (row - 1, col) not in seen and board[row - 1][col] == word[idx]:
            nextSeen = seen[:]
            nextSeen.append((row - 1, col))
            up = dfs(nextSeen, idx + 1, row - 1, col)
        
        # Try right
        if col < len(board[0]) - 1 and (row, col + 1) not in seen and board[row][col + 1] == word[idx]:
            nextSeen = seen[:]
            nextSeen.append((row, col + 1))
            right = dfs(nextSeen, idx + 1, row, col + 1)
        
        # Try left
        if col > 0 and (row, col - 1) not in seen and board[row][col - 1] == word[idx]:
            nextSeen = seen[:]
            nextSeen.append((row, col - 1))
            left = dfs(nextSeen, idx + 1, row, col - 1)
        
        return up or down or left or right
    
    for row in range(len(board)):
        for col in range(len(board[0])):
            if board[row][col] == word[0] and dfs([(row, col)], 1, row, col):
                return True
    
    return False
