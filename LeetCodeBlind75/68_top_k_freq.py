# 347. Top K Frequent Elements
from typing import List
from collections import defaultdict
def topKFrequent(self, nums: List[int], k: int) -> List[int]:
    counts = defaultdict(lambda: 0)
    for num in nums:
        counts[num] += 1

    pairs = [[key, counts[key]] for key in counts.keys()]
    pairs.sort(key=lambda x: x[1], reverse=True)

    return [pairs[i][0] for i in range(k)]
