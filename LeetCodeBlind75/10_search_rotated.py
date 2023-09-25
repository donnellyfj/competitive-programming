# 33. Search in Rotated Sorted Array
from typing import List
def search(self, nums: List[int], target: int) -> int:
    # Restore original array
    l = 0
    r = len(nums) - 1
    while l < r:
        m = (l + r) // 2
        if nums[m] < nums[r] < nums[l] or nums[l] <= nums[m] < nums[r]:
            r = m
        else:
            l = m + 1

    offset = l
    numsOrig = nums[offset:] + nums[:offset]

    # Find target
    l = 0
    r = len(numsOrig) - 1
    while l < r:
        m = (l + r) // 2
        if numsOrig[m] >= target:
            r = m
        else:
            l = m + 1
    
    if numsOrig[l] == target:
        return (l + offset) % len(nums)
    else:
        return -1
