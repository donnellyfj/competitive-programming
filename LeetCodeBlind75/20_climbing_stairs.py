# 70. Climbing Stairs
def climbStairs(self, n: int) -> int:
    if n == 1 or n == 2:
        return n

    dp = [0] * n
    dp[0] = 1
    dp[1] = 2
    
    # Each step i is out[i - 2] + out[i - 1]
    # Since you can take 2 steps up from 2 steps previous, or
    # 1 step up from 1 step previous
    for i in range(2, n):
        dp[i] = dp[i - 2] + dp[i - 1]
    
    return dp[-1]
