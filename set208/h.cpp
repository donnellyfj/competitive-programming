#include <bits/stdc++.h>
using namespace std;

// Serval and Toxel's Arrays

void solve(long long int n, long long int m, vector<int> arr, vector<int> p, vector<int> v) {
    // Intuition: Find contribution to the output sum for each number seen
    long long int out = 0;
    unordered_map<int, long long int> lastSeen;
    unordered_map<int, long long int> counts;
    // Read original input array
    for (int curr : arr) {
        lastSeen[curr] = 0;
    }
    for (int i = 0; i < m; i++) {
        // Find when the value that's about to be changed was added
        counts[arr[p[i]]] += i + 1 - lastSeen[arr[p[i]]];
        arr[p[i]] = v[i];
        lastSeen[v[i]] = i + 1;
    }
    // Read final array
    for (int curr : arr) {
        counts[curr] += m + 1 - lastSeen[curr];
    }

    for (auto [curr, numExists] : counts) {
        // Number of times curr adds to the sum is the number of pairs of
        // arrays containing curr = m+1 + m+1-1 + m+1-2... + m+1-x where
        // x is the number of sets containing curr
        // Use Gaussian sum to find x + x-1 + x-2...
        out += (m + 1) * m / 2 - (m + 1 - numExists) * (m - numExists) / 2;
    }

    cout << out << '\n';
}
 
int main() {
    int t;
    long long int n;
    long long int m;
    vector<int> arr;
    vector<int> p;
    vector<int> v;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        arr.resize(n);
        p.resize(m);
        v.resize(m);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> p[i] >> v[i];
            // Convert to 0 index
            p[i]--;
        }
        solve(n, m, arr, p, v);
    }

    return 0;
}
