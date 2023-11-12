# 242. Valid Anagram
from collections import defaultdict
def isAnagram(self, s: str, t: str) -> bool:
    if len(s) != len(t):
        return False
    counts1 = defaultdict(lambda: 0)
    counts2 = defaultdict(lambda: 0)
    for i in range(len(s)):
        counts1[s[i]] += 1
        counts2[t[i]] += 1
    
    return counts1 == counts2
