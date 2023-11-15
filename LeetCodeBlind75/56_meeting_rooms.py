# 252. Meeting Rooms
from typing import List
def can_attend_meetings(self, intervals: List[Interval]) -> bool:
        # Write your code here
        intervals.sort(key=lambda x: [x.start, x.end])
        # Check for overlap
        for i in range(len(intervals) - 1):
            if intervals[i].start <= intervals[i + 1].start < intervals[i].end:
                return False

        return True
