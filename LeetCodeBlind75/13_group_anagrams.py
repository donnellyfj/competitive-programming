# 49. Group Anagrams
from typing import List
from collections import defaultdict
def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        sortedStrs = ["".join(sorted(s)) for s in strs]
        mapping = defaultdict(lambda: [])

        for i in range(len(strs)):
            mapping[sortedStrs[i]].append(strs[i])
        
        return mapping.values()
