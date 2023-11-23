#include <bits/stdc++.h>
using namespace std;
 
// Great Sequence

void solve(long long int n, long long int x, vector<long long int> arr) {
    // Intuition: Greedily select pairs.
    sort(arr.begin(), arr.end());
    // Keep track of indices that have been paired up already
    vector<int> usedIdx(n, 0);
    long long int out = 0;

    int j = 0;
    for (int i = 0; i < n; i++) {
        // Check if idx has been paired already
        if (usedIdx[i]) {
            continue;
        }
        // Look for x * arr[i] in arr with linear search
        long long int target = x * arr[i];
        while (j < n && arr[j] < target) {
            j++;
        }
        if (j < n && arr[j] == target) {
            usedIdx[j] = 1;
            j++;
        }
        else {
            out += 1;
        }
    }

    cout << out << '\n';
}
 
int main() {
    int t;
    long long int n;
    long long int x;
    vector<long long int> arr;
 
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
