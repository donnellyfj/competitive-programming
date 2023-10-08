# 213. House Robber II
from typing import List
def rob(self, nums: List[int]) -> int:
    def tryHouses(houses):
        dp = [0] * len(houses)
        dp[0] = houses[0]
        for i in range(len(houses)):
            if i < 2:
                dp[i] = max(dp[i - 1], houses[i])
            else:
                dp[i] = max(dp[i - 1], dp[i - 2] + houses[i])
        return dp[-1]

    if len(nums) == 1:
        return nums[0]
    # Try starting at house 0 and ignoring last house
    out1 = tryHouses(nums[:-1])

    # Try starting at house 1 using ignoring last house
    out2 = tryHouses(nums[1:])

    return max(out1, out2)
