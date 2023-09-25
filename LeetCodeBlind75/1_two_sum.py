# 1. Two Sum
from typing import List
def twoSum(self, nums: List[int], target: int) -> List[int]:
    mapping = {}
    for idx in range(len(nums)):
        if target - nums[idx] in mapping:
            return [idx, mapping[target - nums[idx]]]
        mapping[nums[idx]] = idx
    