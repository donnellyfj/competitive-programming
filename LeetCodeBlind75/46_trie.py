# 208. Implement Trie (Prefix Tree)
class Trie:

    def __init__(self):
        self.trie = {}

    def insert(self, word: str) -> None:
        curr = self.trie
        for i in range(len(word)):
            if word[i] not in curr:
                curr[word[i]] = {}
            curr = curr[word[i]]
        curr[True] = True

    def search(self, word: str) -> bool:
        curr = self.trie
        exists = False
        for i in range(len(word)):
            if word[i] not in curr:
                return False
            else:
                curr = curr[word[i]]
        return True in curr

    def startsWith(self, prefix: str) -> bool:
        curr = self.trie
        for i in range(len(prefix)):
            if prefix[i] not in curr:
                return False
            else:
                curr = curr[prefix[i]]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)