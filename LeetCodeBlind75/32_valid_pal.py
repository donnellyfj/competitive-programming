# 125. Valid Palindrome
def isPalindrome(self, s: str) -> bool:
    s = s.lower()
    chars = []
    for i in s:
        if 'a' <= i <= 'z' or '0' <= i <= '9':
            chars.append(i)

    l = 0
    r = len(chars) - 1
    while l < r:
        if chars[l] != chars[r]:
            return False
        l += 1
        r -= 1
    
    return True
