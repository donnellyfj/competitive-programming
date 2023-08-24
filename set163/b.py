getInput = lambda: int(input().split()[0])

def solve(n, nums):
    for i in range(n):
        if nums[i] == 1:
            nums[i] += 1
    for i in range(n - 1):
        while nums[i + 1] % nums[i] == 0:
            nums[i + 1] += 1
    for i in range(n):
        print(nums[i], end=" ")
    print("")

i = getInput()
for _ in range(i):
    n = getInput()
    nums = list(map(int, input().split()))
    solve(n, nums)
