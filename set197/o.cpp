#include <bits/stdc++.h>
using namespace std;

// Equal Tree Sums

unordered_map<int, vector<int>> adj;
vector<int> out;

void dfs(int node, int prev, int sign) {
    out[node - 1] = adj[node].size() * sign;
    for (int neighbor : adj[node]) {
        if (neighbor != prev) {
            dfs(neighbor, node, sign * -1);
        }
    }
}

void solve(int n) {
    // Intuition: Bicolor tree, set each vertex to its degree with alternating sign
    dfs(1, 0, 1);
    
    for (int val : out) {
        cout << val << ' ';
    }
    cout << '\n';
}
 
int main() {
    int t;
    int n;
    int a;
    int b;

    cin >> t;
    while (t--) {
        cin >> n;
        adj.clear();
        out.resize(n);
        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        solve(n);
    }

    return 0;
}
