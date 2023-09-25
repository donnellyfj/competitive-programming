# 3. Longest Substring Without Repeating Characters
from collections import defaultdict
def lengthOfLongestSubstring(self, s: str) -> int:
    curr = defaultdict(lambda: 0)
    l = r = 0
    out = 0
    
    while r < len(s):
        if curr[s[r]] != 0:
            curr[s[l]] -= 1
            l += 1
        else:
            curr[s[r]] += 1
            out = max(out, r - l + 1)
            r += 1
    return out
