# 190. Reverse Bits
def reverseBits(self, n: int) -> int:
    out = 0
    for _ in range(32):
        out = out * 2 + (n & 1)
        n >>= 1

    return out
