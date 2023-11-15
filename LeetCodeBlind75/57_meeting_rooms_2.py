# 253. Meeting Rooms II
from typing import List
def min_meeting_rooms(self, intervals: List[Interval]) -> int:
    # Write your code here
    # Split start and end times
    start = []
    end = []
    for interval in intervals:
        start.append(interval.start)
        end.append(interval.end)
    start.sort()
    end.sort()
    s = e = 0
    out = 0
    while s < len(start) and e < len(end):
        if start[s] < end[e]:
            s += 1
        else:
            e += 1
        out = max(out, s - e)
    
    return out
