#include <bits/stdc++.h>
using namespace std;

// Balanced String

void solve(string s) {
    // Intuition: DP
    int n = s.size();
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 1, vector<int>((n + 1) * (n + 1))));

    // Initialize DP values and solve DP
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i + 1; j++) {
            for (int k = 0; k <= j * (i + 1 - j); k++) {
                dp[1][j][k] = n;
            }
        }

        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= j * (i - j); k++) {
                // Try placing a 0 as the next value of the string
                dp[1][j + 1][k] = min(dp[1][j + 1][k], dp[0][j][k] + (s[i] != '0'));
                // Try placing a 1 as the next value of the string
                dp[1][j][k + j] = min(dp[1][j][k + j], dp[0][j][k] + (s[i] != '1'));
            }
        }
        // Space optimization since all you need are the current and next DP values
        swap(dp[0], dp[1]);
    }
    int num0 = count(s.begin(), s.end(), '0');
    int num1 = n - num0;
    cout << dp[0][num0][num0 * num1 / 2] / 2 << '\n';
}

int main() {
    string s;

    cin >> s;
    solve(s);

    return 0;
}
