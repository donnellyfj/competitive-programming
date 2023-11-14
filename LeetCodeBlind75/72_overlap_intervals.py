# 435. Non-overlapping Intervals
from typing import List
def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
    intervals.sort()
    out = 0
    prev = 0
    curr = prev + 1
    while curr < len(intervals):
        # Check if previous and current intervals overlap
        if intervals[prev][0] <= intervals[curr][0] < intervals[prev][1]:
            # Remove interval with larger second value
            if intervals[prev][1] >= intervals[curr][1]:
                # Effectively popping the element at prev
                prev = curr
            # Check the next interval. If prev is unchanged, then this is the same as popping curr
            curr += 1
            out += 1
        else:
            # Intervals don't overlap, so try the next two while skipping intervals that have been popped
            prev = curr
            curr += 1

    return out
