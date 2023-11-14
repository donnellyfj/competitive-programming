# 424. Longest Repeating Character Replacement
from collections import defaultdict
def characterReplacement(self, s: str, k: int) -> int:
    out = currMax = 0
    l = r = 0
    counts = defaultdict(lambda: 0)
    maxChar = s[0]
    while r < len(s):
        counts[s[r]] += 1
        if counts[s[r]] > counts[maxChar]:
            maxChar = s[r]

        if r - l + 1 - counts[maxChar] > k:
            counts[s[l]] -= 1
            l += 1
        out = max(out, r - l + 1)
        r += 1

    return out
