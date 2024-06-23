#include <bits/stdc++.h>
using namespace std;

// Cover it!

unordered_map<int, vector<int>> adj;
vector<int> even;
vector<int> odd;
set<int> seen;

void dfs(int curr, int dist) {
    seen.insert(curr);
    if (dist % 2) {
        odd.push_back(curr);
    }
    else {
        even.push_back(curr);
    }

    for (int neighbor : adj[curr]) {
        if (seen.find(neighbor) == seen.end()) {
            dfs(neighbor, dist + 1);
        }
    }
}

void solve(int n) {
    // Intuition: Find even/odd distances, use the smallest of the two
    dfs(1, 0);

    if (even.size() <= odd.size()) {
        cout << even.size() << '\n';
        for (int val : even) {
            cout << val << ' ';
        }
    }
    else {
        cout << odd.size() << '\n';
        for (int val : odd) {
            cout << val << ' ';
        }
    }
    
    cout << '\n';
}
 
int main() {
    int t;
    int n;
    int m;
    int a;
    int b;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        adj.clear();
        even.clear();
        odd.clear();
        seen.clear();
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        solve(n);
    }

    return 0;
}
