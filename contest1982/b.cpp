#include <bits/stdc++.h>
using namespace std;

// Collatz Conjecture

void solve(int x, int y, int k) {
    // Intuition: Simulate operations
    while (k > 0) {
        if (x == 1) {
            // Operation cycle to get back to 1 will take y iterations
            x += k % (y - 1);
            break;
        }
        // Find distance to next number divisible by k
        int dist = max(1, (y - x % y) % y);
        x += min(k, dist);
        k -= dist;
        while (x % y == 0 && k >= 0 && y != 1) {
            x /= y;
        }
        // Subract from k if not already done this iteration
        if (dist == 0) {
            k--;
        }
    }
    cout << x << '\n';
}

int main() {
    int t;
    int x;
    int y;
    int k;

    cin >> t;
    while (t--) {
        cin >> x >> y >> k;
        solve(x, y, k);
    }

    return 0;
}
