def main():
    t = int(input())
    for _ in range(t):
        x = int(input())
        arr = []

        # Intuition: Repeatedly subtract largest power of 2 that is less than the current value,
        #            and that evenly divides current value.
        while x > 0:
            exp = 2
            while x % exp == 0 and exp < x:
                exp *= 2
            exp /= 2

            arr.append(x)
            x -= exp
        print(len(arr))
        for val in arr:
            print(int(val), end=" ")
        print() # Newline

if __name__ == "__main__":
    main()
