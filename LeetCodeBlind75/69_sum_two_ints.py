# 371. Sum of Two Integers
def getSum(self, a: int, b: int) -> int:
    def adder(aBits, bBits):
        outBits = [0] * len(aBits)
        carry = 0

        for i in range(len(aBits) - 1, -1, -1):
            outBits[i] = aBits[i] | bBits[i] | carry
            if aBits[i] & bBits[i] or aBits[i] & carry | bBits[i] & carry:
                if aBits[i] & bBits[i] & carry:
                    outBits[i] = 1
                else:
                    outBits[i] = 0
                carry = 1
            else:
                carry = 0
        
        return outBits

    # Trivial cases
    if a == -b:
        return 0
    if a == 0:
        return b
    if b == 0:
        return a

    aBin = bin(a)
    bBin = bin(b)
    aNeg = a < 0
    bNeg = b < 0
    if aNeg:
        a *= -1
    if bNeg:
        b *= -1

    aBits = [int(bit) for bit in bin(a)[2:]]
    bBits = [int(bit) for bit in bin(b)[2:]]

    while len(aBits) < len(bBits):
        aBits.insert(0,0)
    while len(bBits) < len(aBits):
        bBits.insert(0,0)

    # If one number is negative, make sure it's the smaller number
    negFlag = False
    if aNeg ^ bNeg:
        if (aNeg and a > b) or (bNeg and b > a):
            negFlag = True
            aNeg, bNeg = bNeg, aNeg

    # 1's complement negative numbers
    if aNeg and not bNeg:
        aBits = [1 if i == 0 else 0 for i in aBits]
    if bNeg and not aNeg:
        bBits = [1 if i == 0 else 0 for i in bBits]
    aBits.insert(0,0)
    bBits.insert(0,0)

    outBits = adder(aBits, bBits)

    out = 0
    if aNeg ^ bNeg:
        addBit = [0] * len(outBits)
        addBit[-1] = outBits[0]

        outBits[0] = 0
        outBits = adder(outBits, addBit)[1:]

    for bit in outBits:
        out <<= 1
        out |= bit
    
    if aNeg and bNeg or negFlag:
        out *= -1
    
    return out
