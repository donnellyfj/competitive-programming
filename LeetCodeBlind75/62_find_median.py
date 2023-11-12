# 295. Find Median from Data Stream
class MedianFinder:

    def __init__(self):
        self.nums = []
        

    def addNum(self, num: int) -> None:
        # insort(self.nums, num) <- Can just use this instead of binary search
        l = 0
        r = len(self.nums)
        while (l < r):
            m = (l + r) // 2
            if (num > self.nums[m]):
                l = m + 1
            else:
                r = m
        self.nums.insert(l, num)

    def findMedian(self) -> float:
        if len(self.nums) % 2:
            return self.nums[len(self.nums) // 2]
        else:
            return (self.nums[len(self.nums) // 2] + self.nums[len(self.nums) // 2 - 1]) / 2


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
