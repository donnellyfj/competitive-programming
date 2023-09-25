# 15. 3Sum
from typing import List
from collections import defaultdict
def threeSum(self, nums: List[int]) -> List[List[int]]:
    seen = defaultdict(lambda: 0)
    nums2 = [] # Remove occurances of numbers that appear more than 3 times
    for num in nums:
        if seen[num] <= 3:
            nums2.append(num)
            seen[num] += 1

    nums = nums2
    nums.sort()
    out = set()

    for i in range(len(nums) - 2):
        l = i + 1
        r = len(nums) - 1
        while l < r:
            if nums[i] + nums[l] + nums[r] == 0:
                out.add(tuple(sorted([nums[i], nums[l], nums[r]])))
                r -= 1
            elif nums[i] + nums[l] + nums[r] > 0:
                r -= 1
            else:
                l += 1

    return out
