#include <bits/stdc++.h>
using namespace std;

// Full Turn

void solve(int n, vector<vector<int>> arr) {
    // Intuition: Keep track of slope, add points with opposite slope.
    long long int out = 0;
    map<vector<int>, int> seen;

    for (int i = 0; i < n; i++) {
        int x = arr[i][0];
        int y = arr[i][1];
        int u = arr[i][2];
        int v = arr[i][3];

        // Slope intercept form
        int m1 = (u - x) / gcd(u - x, v - y);
        int m2 = (v - y) / gcd(u - x, v - y);

        // Handle verticle/horizontal lines
        if (m1 == 0) {
            m2 /= abs(m2);
        }
        if (m2 == 0) {
            m1 /= abs(m1);
        }

        // Add points with opposite slope
        out += seen[{-m1, -m2}];

        seen[{m1, m2}]++;
    }
    
    cout << out << '\n';
}

int main() {
    int t;
    int n;
    vector<vector<int>> arr;
 
    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            arr[i].resize(4);
            cin >> arr[i][0];
            cin >> arr[i][1];
            cin >> arr[i][2];
            cin >> arr[i][3];
        }
        solve(n, arr);
    }
 
    return 0;
}
