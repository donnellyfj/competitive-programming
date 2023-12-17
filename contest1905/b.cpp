#include <bits/stdc++.h>
using namespace std;
 
// Begginer's Zelda
 
void solve(int n, vector<vector<int>> arr) {
    // Intuition: Ceil(# of elements with 3+ edges / 2) + 1
    unordered_map<int, int> adj;
    int out = 0;

    for (int i = 0; i < n - 1; i++) {
        adj[arr[i][0]]++;
        adj[arr[i][1]]++;
        if (adj[arr[i][0]] > 2) {
            out++;
        }
        if (adj[arr[i][1]] > 2) {
            out++;
        }
    }

    cout << out / 2 + (out % 2) + 1 << '\n';
}
 
int main() {
    int t;
    int n;
    vector<vector<int>> arr;
 
    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n - 1);
        for (int i = 0; i < n - 1; i++) {
            arr[i].resize(2);
            cin >> arr[i][0] >> arr[i][1];
        }
        solve(n, arr);
    }
 
    return 0;
}
