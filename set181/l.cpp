#include <bits/stdc++.h>
using namespace std;
 
// Yet Another Problem On a Subsequence

const int MOD = 998244353;

void solve(int n, vector<int> arr) {
    // Intuition: DP from right to left along the array, using formula to count combinations.
    // Precompute combination values
    vector<vector<long long int>> comb(1001, vector<long long int> (1001, 0));
    for (int i = 0; i < 1001; i++) {
        comb[i][i] = comb[i][0] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
        }
    }

    vector<long long int> dp(n + 1);
    dp.back() = 1;

    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] <= 0) {
            continue;
        }
        for (int j = i + arr[i] + 1; j < n + 1; j++) {
            dp[i] = (dp[i] + (dp[j] * comb[j - i - 1][arr[i]])) % MOD;
        }
    }

    long long int out = 0;
    for (int i = 0; i < n; i++) {
        out = (out + dp[i]) % MOD;
    }

    cout << out << '\n';
}

int main() {
    int n;
    vector<int> arr;
 
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solve(n, arr);
 
    return 0;
}
