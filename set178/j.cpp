#include <bits/stdc++.h>
using namespace std;
 
// Two Hundred Twenty One (easy version)

// NOTE: Have to declare arr here, doing it in main and passing as a parameter to solve() will cause TLE
vector<int> arr(1000000 + 5);

void solve(int n, int l, int r) {
    // Intuition: Check sign-variable sum of interval, as well as the parity of the segment length.
    int sum = arr[r] - arr[l - 1];

    // If starting index is even, the sum should be negated since the order of signs will be flipped.
    if (l % 2 == 0) {
        sum *= -1;
    }

    if (sum == 0) {
        cout << 0 << '\n';
    }
    else if ((r - l + 1) % 2) {
        cout << 1 << '\n';
    }
    else {
        cout << 2 << '\n';
    }
}

int main() {
    int t;
    int n;
    int q;
    int l; 
    int r;
    char temp;
 
    cin >> t;
    while (t--) {
        cin >> n >> q;
        arr[0] = 1;
        for (int i = 1; i <= n; i++) {
            cin >> temp;
            if (temp == '+') {
                arr[i] = 1;
            }
            else {
                arr[i] = -1;
            }
        }
        // Get prefix sum
        int sign = 1;
        for (int i = 1; i <= n; i++) {
            arr[i] = arr[i - 1] + arr[i] * sign;
            sign *= -1;
        }
        for (int j = 0; j < q; j++) {
            cin >> l >> r;
            solve(n, l, r);
        }
    }
 
    return 0;
}
