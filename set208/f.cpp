#include <bits/stdc++.h>
using namespace std;

// Turtle and an Infinite Sequence

void solve(long long int n, long long int m) {
    // Intuition: Check if some value will be in the second half of each power of 2
    long long int out = n;
    // For each bit, the bit will be a 1 if in the second half of the next power of 2
    // Check if each bit will be a 1 at some point between n - m and n + m
    long long int currBit = 1;
    while (currBit <= n + m) {
        // min(n, m) since n - m has a lower bound of 0
        if (min(n, m) + m > currBit) {
            out |= currBit;
        }
        else {
            long long int temp1 = (max(0ll, n - m)) % (currBit * 2);
            long long int temp2 = (n + m) % (currBit * 2);
            if (temp1 >= currBit || temp2 >= currBit) {
                out |= currBit;
            }
        }

        currBit <<= 1;
    }

    cout << out << '\n';
}
 
int main() {
    int t;
    long long int n;
    long long int m;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        solve(n, m);
    }

    return 0;
}
