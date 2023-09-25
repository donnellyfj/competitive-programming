# 56. Merge Intervals
from typing import List
def merge(self, intervals: List[List[int]]) -> List[List[int]]:
    intervals.sort()
    out = []
    lBound = intervals[0][0]
    rBound = intervals[0][1]
    for l, r in intervals[1:]:
        if l > rBound:
            out.append([lBound, rBound])
            lBound = l
        rBound = max(r, rBound)
    
    out.append([lBound, rBound])
    
    return out
