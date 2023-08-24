#include <bits/stdc++.h>
using namespace std;

// Making Towers

void solve(int n, vector<int> arr) {
    int parity;
    int color;

    vector<vector<int>> dp(2, vector<int>(n));
    for (int i = 0; i < n; i++) {
        color = arr[i] - 1;
        parity = (i + 1) % 2;
        dp[parity][color] = max(dp[parity][color], dp[!parity][color] + 1);
    }

    for (int i = 0; i < n; i++) {
        cout << max(dp[0][i], dp[1][i]) << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    int n;
    vector<int> arr;

    // cout << "Input num of test cases: ";
    scanf("%d", &t);

    while (t--) {
        // cout << "Input array size: ";
        scanf("%d", &n);
        arr.resize(n);
        // cout << "Input array: ";
        for (int idx = 0; idx < n; idx++) {
            scanf("%d", &arr[idx]);
        }

        solve(n, arr);
    }
}