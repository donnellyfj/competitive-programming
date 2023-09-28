# 139. Work Break
from typing import List
def wordBreak(self, s: str, wordDict: List[str]) -> bool:
    dp = [[s]]
    while dp[-1]:
        strings = dp[-1]
        nxtStrings = set()
        for string in strings:
            if string == "":
                return True
            for word in wordDict:
                if word in string:
                    startIdx = string.index(word)
                    if startIdx == 0:
                        nxtStrings.add(string[startIdx + len(word):])
            dp.append(nxtStrings)

    return False
