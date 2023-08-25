#include <bits/stdc++.h>
using namespace std;

// Almost Ternary Matrix

void solve(int n, int m) {
    int shift;
    for (int i = 0; i < n; i++) {
        shift = ((i + 1) % 4) >= 2;
        for (int j = 0; j < m; j++) {
            cout << (((j + 3 + shift * 2) % 4) >= 2) << ' ';
        }
        cout << '\n';
    }
}

int main() {
    int t;
    int n, m;

    // cout << "Input num of test cases: ";
    cin >> t;

    while (t--) {
        // cout << "Input array size: ";
        cin >> n >> m;

        solve(n, m);
    }

    return 0;
}
