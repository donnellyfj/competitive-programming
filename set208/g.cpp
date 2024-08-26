#include <bits/stdc++.h>
using namespace std;

// Increase Subarray Sums

void solve(int n, int x, vector<int> arr) {
    // Intuition: Get max sums for all lengths, then add x as needed for each one
    vector<int> maxSums(n + 1, INT_MIN);
    for (int i = 0; i < n; i++) {
        int currSum = 0;
        for (int j = i; j < n; j++) {
            currSum += arr[j];
            maxSums[j - i + 1] = max(maxSums[j - i + 1], currSum);
        }
    }
    
    for (int i = 0; i <= n; i++) {
        int out = 0;
        for (int j = 1; j <= n; j++) {
            out = max(out, maxSums[j] + min(j, i) * x);
        }
        cout << out << ' ';
    }

    cout << '\n';
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
