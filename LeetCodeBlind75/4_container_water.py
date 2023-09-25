# 11. Container With Most Water
from typing import List
def maxArea(self, height: List[int]) -> int:
    l = 0
    r = len(height) - 1
    out = 0

    while l < r:
        out = max(out, min(height[l], height[r]) * (r - l))
        if height[l] < height[r]:
            l += 1
        else:
            r -= 1

    return out
