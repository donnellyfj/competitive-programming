# 53. Maximum Subarray
from typing import List
def maxSubArray(self, nums: List[int]) -> int:
    out = curr = nums[0]
    r = l = 0
    while r < len(nums):
        if nums[r] > curr:
            curr = nums[r]
            l = r
        else:
            r += 1
            if r < len(nums):
                curr += nums[r]
        out = max(out, curr)
    
    return out
