#include <bits/stdc++.h>
using namespace std;

// Great Grids

vector<vector<pair<int, int>>> adj(4000);
vector<int> colors(4000);
string out = "YES";

void dfs(int node, int color) {
    if (colors[node] != -1) {
        if (colors[node] != color) {
            out = "NO";
        }
        return;
    }
    colors[node] = color;

    // Traverse to neighbors
    for (auto [neighbor, direction] : adj[node]) {
        dfs(neighbor, color ^ direction);
    }
}

void solve(int n, int m) {
    // Intuition: Two color DFS.
    // Reset global variables
    out = "YES";
    fill(colors.begin(), colors.begin() + n + m, -1);

    // DFS over all connected segments
    for (int i = 0; i < n + m; i++) {
        if (colors[i] == -1) {
            dfs(i, 0);
        }
    }
    
    cout << out << '\n';
}

int main() {
    int t;
    int n;
    int m;
    int k;
    int r1, r2, c1, c2;

    cin >> t;
    while (t--) {
        // Reset global variables
        fill(adj.begin(), adj.end(), vector<pair<int, int>>());

        cin >> n >> m >> k;
        for (int i = 0; i < k; i++) {
            cin >> r1 >> c1 >> r2 >> c2;
            adj[min(r1, r2)].push_back({n + min(c1, c2), (r1 + c1) != (r2 + c2)});
            adj[n + min(c1, c2)].push_back({min(r1, r2), (r1 + c1) != (r2 + c2)});
        }
        solve(n, m);
    }
 
    return 0;
}
