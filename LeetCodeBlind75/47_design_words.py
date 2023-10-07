class WordDictionary:

    def __init__(self):
        self.trie = {}

    def addWord(self, word: str) -> None:
        curr = self.trie
        for letter in word:
            if letter not in curr:
                curr[letter] = {}
            curr = curr[letter]
        # Mark that a word ends here
        curr[True] = True

    def search(self, word: str) -> bool:
        def dfs(idx, curr):
            if idx == len(word):
                if True in curr:
                    return True
                else:
                    return False
            
            if word[idx] == '.':
                for key in curr.keys():
                    if key != True:
                        if dfs(idx + 1, curr[key]) == True:
                            return True
            elif word[idx] in curr:
                return dfs(idx + 1, curr[word[idx]])
            else:
                return False
        
        return dfs(0, self.trie)



# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
