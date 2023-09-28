# 128. Longest Consecutive Sequence
from typing import List
def longestConsecutive(self, nums: List[int]) -> int:
    nums.sort()
    out = min(1, len(nums))
    curr = 1

    for i in range(len(nums) - 1):
        if nums[i + 1] == nums[i] + 1:
            curr += 1
            out = max(out, curr)
        elif nums[i + 1] > nums[i] + 1:
            curr = 1

    return out
