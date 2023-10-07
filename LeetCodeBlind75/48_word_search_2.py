# 212. Word Search II
def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
    trie = {}
    out = set()

    # Add a word to the trie
    def addWord(word):
        curr = trie
        for letter in word:
            if letter not in curr:
                curr[letter] = {}
            curr= curr[letter]
        curr['*'] = word
    
    # After a word has been found, we can remove it from the trie
    def removeWord(word):
        curr = trie
        stack = []
        for letter in word:
            stack.append((letter, curr))
            curr = curr[letter]
        curr.pop('*')
        while stack:
            letter, curr = stack.pop()
            if '*' in curr and curr['*'] not in out or curr[letter] != {}:
                break
            curr.pop(letter)
    
    seen = []
    for i in range(len(board)):
        seen.append([0] * len(board[0]))
    
    # Look for words recursively
    def search(row, col, curr):
        if board[row][col] not in curr:
            return
        seen[row][col] = 1
        curr = curr[board[row][col]]
        if '*' in curr:
            out.add(curr['*'])
            removeWord(curr['*'])
        # Try up
        if row > 0 and seen[row - 1][col] == 0:
            search(row - 1, col, curr)
        # Try down
        if row < len(board) - 1 and seen[row + 1][col] == 0:
            search(row + 1, col, curr)
        # Try left
        if col > 0 and seen[row][col - 1] == 0:
            search(row, col - 1, curr)
        # Try right
        if col < len(board[0]) - 1 and seen[row][col + 1] == 0:
            search(row, col + 1, curr)
        
        seen[row][col] = 0

    # Add all words to the trie
    for word in words:
        addWord(word)
    # Search starting at all indices of the board
    for row in range(len(board)):
        for col in range(len(board[0])):
            search(row, col, trie)

    return out
