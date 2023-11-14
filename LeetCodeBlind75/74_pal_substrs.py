# 647. Palindromic Substrings
def countSubstrings(self, s: str) -> int:
    def check(l, r):
        count = 0
        while l >= 0 and r < len(s):
            if s[l] == s[r]:
                count += 1
            else:
                break
            l -= 1
            r += 1

        return count

    out = 0
    for i in range(len(s)):
        out += check(i, i)
        out += check(i, i + 1)
    
    return out
