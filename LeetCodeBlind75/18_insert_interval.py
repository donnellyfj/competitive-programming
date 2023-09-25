# 57. Insert Interval
from typing import List
def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
    # Binary search to insert new interval
    l = 0
    r = len(intervals)
    while l < r:
        m = (l + r) // 2
        if intervals[m][0] < newInterval[0]:
            l = m + 1
        else:
            r = m
    
    # Insert new interval
    intervals.insert(l, newInterval)

    # Merge starting at one before insertion point, or beginning of array if inserted at 0
    lBound = newInterval[0]
    rBound = newInterval[1]
    idx = max(0, l - 1)

    # Stop merging if at end of array or new interval doesn't overlap with the next interval
    while idx < len(intervals) - 1 and idx < l + 1:
        if intervals[idx][1] >= intervals[idx + 1][0]:
            intervals[idx][1] = max(intervals[idx][1], intervals[idx + 1][1])
            intervals.pop(idx + 1)
        else:
            idx += 1
    
    return intervals
