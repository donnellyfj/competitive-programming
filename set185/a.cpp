#include <bits/stdc++.h>
using namespace std;
 
// Remove Smallest

void solve(int n, vector<int> arr) {
    // Intuition: Sort and check consecutive differences.
    sort(arr.begin(), arr.end());
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[i - 1] > 1) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
}

int main() {
    int t;
    int n;
    vector<int> arr;
 
    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(n, arr);
    }
 
    return 0;
}
