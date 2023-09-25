# 55. Jump Game
from typing import List
def canJump(self, nums: List[int]) -> bool:
    # If there is a number that is 0 (that isn't the last element), check if it can be skipped
    for i in range(len(nums) - 1):
        if nums[i] == 0:
            checkIdx = i
            while checkIdx >= 0:
                if checkIdx + nums[checkIdx] > i:
                    break
                checkIdx -= 1
            
            # There were no values that can skip the last seen 0
            if checkIdx < 0:
                return False
    
    return True
