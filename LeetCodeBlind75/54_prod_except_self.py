# 238. Product of Array Except Self
from typing import List
def productExceptSelf(self, nums: List[int]) -> List[int]:
    prefix = 1
    suffix = 1
    out = [1] * len(nums)
    for i in range(len(nums)):
        out[i] *= prefix
        prefix *= nums[i]
    for i in range(len(nums) -  1, -1, -1):
        out[i] *= suffix
        suffix *= nums[i]

    return out