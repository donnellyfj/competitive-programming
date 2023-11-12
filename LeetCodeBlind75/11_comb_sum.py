# 39. Combination Sum
from typing import List
def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
    out = []
    def dfs(idx, currSum, nums):
        if currSum >= target:
            if currSum == target:
                out.append(nums)
            return
        
        for i in range(idx, len(candidates)):
            dfs(i, currSum + candidates[i], nums + [candidates[i]])
    
    dfs(0, 0, [])

    return out
