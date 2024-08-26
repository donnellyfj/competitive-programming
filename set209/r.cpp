#include <bits/stdc++.h>
using namespace std;

// Idependent Set

unordered_map<long long int, vector<long long int>> adj;
vector<vector<long long int>> dp(300005, vector<long long int>(2));
vector<long long int> dp2(300005);
long long int MOD = 998244353;
long long int mult(long long int a, long long int b) {
    a = (a % MOD + MOD) % MOD;
    b = (b % MOD + MOD) % MOD;
    return (1ll * a * b) % MOD;
}

void dfs(long long int node, long long int prev) {
    dp[node][0] = dp[node][1] = dp2[node] = 1;
    for (int neighbor : adj[node]) {
        if (neighbor == prev) {
            continue;
        }
        dfs(neighbor, node);
        dp[node][0] = mult(dp[node][0], 2 * dp[neighbor][1] + 2 * dp[neighbor][0] - dp2[neighbor]);
        dp[node][1] = mult(dp[node][1], dp[neighbor][1] + 2 * dp[neighbor][0] - dp2[neighbor]);
        dp2[node] = mult(dp2[node], dp[neighbor][1] + dp[neighbor][0] - dp2[neighbor]);
    }
}

void solve(long long int n) {
    // Intuition: Tree DP via DFS
    dfs(1, 0);
    cout << (dp[1][0] + dp[1][1] - dp2[1] - 1 + 2 * MOD) % MOD << '\n';
}

int main() {
    long long int n;

    cin >> n;
    // Build adj
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve(n);

    return 0;
}
