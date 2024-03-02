#include <bits/stdc++.h>
using namespace std;

// Cross Coloring

const int MOD = 998244353;

void solve(int n, int m, int k, int q, vector<vector<int>> arr) {
    // Intuition: Find num of visible queries at the end, take k to the power of this number.
    long long int out = 1;
    set<int> seenRows;
    set<int> seenCols;

    // Read queries backwards
    for (int i = q - 1; i >= 0; i--) {
        // If a query's row and col aren't repeated and if all rows/cols haven't been colored, it is visible at the end
        if (!(seenRows.count(arr[i][0]) * seenCols.count(arr[i][1])) && (seenRows.size() < n) && (seenCols.size() < m)) {
            out = (out * k) % MOD;
        }

        // Update seen data
        seenRows.insert(arr[i][0]);
        seenCols.insert(arr[i][1]);
    }

    // Calculate possible color combinations
    cout << out << '\n';
}

int main() {
    int t;
    int n;
    int m;
    int k;
    int q;
    vector<vector<int>> arr;
 
    cin >> t;
    while (t--) {
        cin >> n >> m >> k >> q;
        arr.resize(q, vector<int>(2));

        for (int i = 0; i < q; i++) {
            cin >> arr[i][0] >> arr[i][1];
        }

        solve(n, m, k, q, arr);
    }
 
    return 0;
}
