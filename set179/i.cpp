#include <bits/stdc++.h>
using namespace std;
 
// Interesting Sequence
 
void solve(long long int n, long long int x) {
    // Intuition: Remove bits from right to left
    long long int mLower = n;
    long long int mUpper = __LONG_LONG_MAX__;
    long long int deleteBits = 0;

    for (long long int i = 0; i < 64; i++) {
        // Check if there exists a set bit in x that doesn't exist in n
        if (!((1ll << i) & n)) {
            if ((1ll << i) & x) {
                cout << -1 << '\n';
                return;
            }
        }
        else {
            // We need to remove the current bit from n if it's set and it's not set in x
            // Create a number equal to n with the lower i bits zeroed out
            long long int curr = n + (1ll << i) - (n & deleteBits);
            if ((1ll << i) & x) {
                // This bit is set in x, so we need to keep it and can't remove it in the future
                mUpper = min(mUpper, curr);
            }
            else {
                // This bit doesn't exist in x, so we need to remove it from n
                mLower = max(mLower, curr);
            }
        }

        // Add the current bit to the mask of bits to create a prefix of zeros
        deleteBits += 1ll << i;
    }

    if (mLower < mUpper) {
        cout << mLower << '\n';
    }
    else {
        cout << -1 << '\n';
    }
}
 
int main() {
    int t;
    long long int n;
    long long int x;
 
    cin >> t;
    while (t--) {
        cin >> n >> x;
        solve(n, x);
    }
 
    return 0;
}
