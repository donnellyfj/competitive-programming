from typing import List
# 121. Best Time to Buy and Sell Stock
def maxProfit(self, prices: List[int]) -> int:
    out = 0
    l = r = 0
    while r < len(prices):
        if prices[r] < prices [l]:
            l = r
        else:
            out = max(out, prices[r] - prices[l])
            r += 1

    return out
