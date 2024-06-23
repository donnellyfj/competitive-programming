#include <bits/stdc++.h>
using namespace std;

// New Year and Handle Change

const int nMax = 1e6 + 10;
int n;
int k;
int l;
string s;
vector<int> arr(nMax, 0);
// DP[i] -> {cost_i, count_i} for prefix of length i
vector<pair<int, int>> dp(nMax);

int calc(int m) {
    // Initialize DP as max values
    for (int i = 0; i <= n; i++) {
        dp[i] = {INT_MAX, INT_MAX};
    }

    // Base case, no cost for 0 length prefix
    dp[0] = make_pair(0, 0);

    // Loop through each character in the handle
    for (int i = 0; i < n; i++) {
        // Try not using a new operation (cost goes up by value of arr[i], operations stays the same)
        if (dp[i + 1] > make_pair(dp[i].first + arr[i], dp[i].second)) {
            dp[i + 1] = {dp[i].first + arr[i], dp[i].second};
        }
        // Try using a new operation (cost goes up by current lambda, operations goes up by 1)
        if (dp[min(n, i + l)] > make_pair(dp[i].first + m, dp[i].second + 1)) {
            dp[min(n, i + l)] = {dp[i].first + m, dp[i].second + 1};
        }
    }

    // Return number of operations
    return dp[n].second;
}

int solve() {
    // Intuition: Lambda optimization, binary search for optimal value and calculate DP
    int l = 0;
    int r = n;
    while (l < r) {
        int m = (l + r) / 2;
        // Check if you can't minimize with less than k operations
        if (calc(m) > k) {
            // Tighten restriction
            l = m + 1;
        }
        else {
            // Relax restriction
            r = m;
        }
    }

    calc(l);
    // Calculate output from the DP by removing the artificial cost l
    return dp[n].first - (l) * 1ll * k;
}
 
int main() {
    cin >> n >> k >> l >> s;
    // Try optimizing for lowercase letters
    for (int i = 0; i < n; i++) {
        arr[i] = islower(s[i]) > 0;
    }
    int out = solve();
    // Try optimizing for uppercase letters
    for (int i = 0; i < n; i++) {
        arr[i] = isupper(s[i]) > 0;
    }
    out = min(out, solve());
    cout << out << '\n';

    return 0;
}
