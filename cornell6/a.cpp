#include <bits/stdc++.h>
using namespace std;
 
// Great Sequence

void solve(int n, int x, vector<int> arr) {
    // Intuition: Greedily select pairs.
    sort(arr.begin(), arr.end());
    vector<int> seen(n, 0);
    int out = 0;
    int r = 0;
    for (int l = 0; l < n; l++) {
        if (seen[l]) {
            continue;
        }
        long long int target;
        target = (long long)arr[l] * x;
        // Look for target
        while (r < n && arr[r] < target) {
            r++;
        }
        if (r < n && arr[r] == target) {
            seen[r]++;
            r++;
        }
        else {
            out++;
        }
    }

    cout << out << '\n';
}
 
int main() {
    int t;
    int n;
    int x;
    vector<int> arr;
 
    cin >> t;
    while (t--) {
        cin >> n >> x;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(n, x, arr);
    }
 
    return 0;
}
