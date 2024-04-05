#include <bits/stdc++.h>
using namespace std;

// Jumping Through Segments

bool jump(int n, int k, vector <vector<long long int>> arr) {
    long long int l = 0;
    long long int r = 0;

    for (int i = 0; i < n; i++) {
        // Get current segment you can jump to
        l = l - k;
        r = r + k;

        // Find inersection with platform
        l = max(l, arr[i][0]);
        r = min(r, arr[i][1]);

        if (l > r) {
            return false;
        }
    }

    return true;
}

void solve(int n, vector <vector<long long int>> arr) {
    // Intuition: Binary search jump lengths
    long long int l = 0;
    long long int r = 1000000000;
    long long int m;

    while (l < r) {
        m = (l + r) / 2;

        if (jump(n, m, arr)) {
            r = m;
        }
        else {
            l = m + 1;
        }
    }

    cout << l << '\n';
}
 
int main() {
    int t;
    int n;
    vector <vector<long long int>> arr;

    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            arr[i].resize(2);
            cin >> arr[i][0] >> arr[i][1];
        }
        solve(n, arr);
    }

    return 0;
}
