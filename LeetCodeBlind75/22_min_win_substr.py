# 76. Minimum Window Substring
from collections import Counter
def minWindow(self, s: str, t: str) -> str:
        l = r = 0
        out = ""
        outLen = float('inf')
        counts = dict(Counter(t))
        for i in t:
            counts[i] = 0
        tCounts = dict(Counter(t))
        reqs = 0
        targetReq = len(tCounts.values())

        while l < len(s):
            # Check if target exists within current window
            if reqs == targetReq:
                if r - l < outLen:
                    out = "".join(s[l:r])
                    outLen = r - l
                if s[l] in counts:
                    counts[s[l]] -= 1
                    if counts[s[l]] < tCounts[s[l]]:
                        reqs -= 1
                l += 1
            elif r < len(s):
                if s[r] in tCounts:
                    counts[s[r]] += 1
                    if counts[s[r]] == tCounts[s[r]]:
                        reqs += 1
                    if s[l] == s[r] and counts[s[r]] > tCounts[s[r]]:
                        counts[s[l]] -= 1
                        l += 1
                r += 1
            else:
                l += 1

        return out
