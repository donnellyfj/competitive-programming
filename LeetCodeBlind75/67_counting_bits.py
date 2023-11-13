# 338. Counting Bits
from typing import List
from math import floor, log2
def countBits(self, n: int) -> List[int]:
    out = [0] * (n + 1)
    for num in range(1, n + 1):
        out[num] = 1 + out[num - 2 ** floor(log2(num))]
    
    return out
