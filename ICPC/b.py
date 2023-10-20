getInput = lambda: int(input().split()[0])

def solve(n, h, arr):
    time = 0
    i = 0
    arr = [0] + arr
    while i < len(arr):
        if h > n + 1 - i:
            print("YES")
            return
        if i == n:
            if h > 0:
                print("YES")
            else:
                print("NO")
            return
        
        # Wait before moving
        if i > 0 and arr[i + 1] > 0 and h > 2:
            steps = (h - 1) // 2
            time += 2 * steps
            h -= 2 * steps
        # Move and eat watermelon
        i += 1
        if arr[i] > 0:
            h += arr[i] + time
        h -=1
        if h <= 0:
            print("NO")
            return
        time += 1


n, h = list(map(int, input().split()))
arr = list(map(int, input().split()))
solve(n, h, arr)
