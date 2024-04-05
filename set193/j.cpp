#include <bits/stdc++.h>
using namespace std;

// Road Optimization

void solve(int n, int l, int k, vector<int> arr, vector<int> pos) {
    // Intuition: DP over the points.
    // Add ending point to arrays
    arr.push_back(0);
    pos.push_back(l);
    n++;
    vector<vector<long long int>> dp(n, vector<long long int>(k + 1, INT_MAX));
    // Start at point 0 at time 0
    dp[0] = vector<long long int>(k + 1, 0ll);

    for (int i = 1; i < n; i++) {
        // Calculate time without removing any signs
        dp[i][0] = dp[i - 1][0] + (pos[i] - pos[i - 1]) * arr[i - 1];
        for (int j = 0; j <= k; j++) {
            // Iterate over what sign should come before the current sign
            for (int prev = max(0, i - j - 1); prev < i; prev++) {
                // See what previous sign gets you to the current position fastest while removing at most j signs
                dp[i][j] = min(dp[i][j], dp[prev][j - (i - prev - 1)] + (pos[i] - pos[prev]) * arr[prev]);
            }
        }
    }

    
    cout << *min_element(dp.back().begin(), dp.back().end()) << '\n';
}

int main() {
    int n;
    int l;
    int k;
    vector<int> arr;
    vector<int> pos;

    cin >> n >> l >> k;
    arr.resize(n);
    pos.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solve(n, l, k, arr, pos);
 
    return 0;
}
