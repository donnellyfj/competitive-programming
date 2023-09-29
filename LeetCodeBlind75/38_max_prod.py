# 152. Maximum Product Subarray
from typing import List
def maxProduct(self, nums: List[int]) -> int:
    out = currMin = currMax = nums[0]
    for i in range(1, len(nums)):
        if nums[i] < 0:
            currMin, currMax = currMax, currMin
        
        currMax = max(nums[i], currMax * nums[i])
        currMin = min(nums[i], currMin * nums[i])
        out = max(out, currMax)

    return out
