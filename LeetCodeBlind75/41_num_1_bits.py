# 191. Number of 1 Bits
def hammingWeight(self, n: int) -> int:
    out = 0
    while n:
        out += n & 1
        n //= 2
    
    return out
