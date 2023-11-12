# 268. Missing Number
from typing import List
def missingNumber(self, nums: List[int]) -> int:
    nums.sort()
    out = 0
    for num in nums:
        if out != num:
            break
        out += 1
    
    return out