#5. Longest Palindromic Substring
def longestPalindrome(self, s: str) -> str:
    out = [0, 0, 0]

    for idx in range(len(s)):
        # Check odd palindrome
        l = r = idx
        while l > 0 and r < len(s) - 1 and s[l - 1] == s[r + 1]:
            l -= 1
            r += 1
        if r - l + 1 > out[0]:
            out = [r - l + 1, l, r]
        
        # Check even palindrome
        if idx < len(s) - 1 and s[idx] == s[idx + 1]:
            l = idx
            r = idx + 1
            while l > 0 and r < len(s) - 1 and s[l - 1] == s[r + 1]:
                l -= 1
                r += 1
            if r - l + 1 > out[0]:
                out = [r - l + 1, l, r]

    return s[out[1] : out[2] + 1]
