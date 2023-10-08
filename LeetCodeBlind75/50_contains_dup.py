# 217. Contains Duplicate
from typing import List
def containsDuplicate(self, nums: List[int]) -> bool:
    return len(nums) != len(set(nums))
