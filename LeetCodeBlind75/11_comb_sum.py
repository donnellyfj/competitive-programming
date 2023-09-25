# 39. Combination Sum
from typing import List
def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
    out = []
    def makeSum(nums, currSum):
        nonlocal out
        if currSum >= target:
            if currSum == target:
                sortNums = sorted(nums)
                if sortNums not in out:
                    out.append(sortNums)
            return

        for i in candidates:
            makeSum(nums + [i], currSum + i)

    makeSum([], 0)
    return out
