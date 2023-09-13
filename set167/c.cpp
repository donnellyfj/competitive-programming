#include <bits/stdc++.h>
using namespace std;
 
// Consecutive Points Segment
 
void solve(int n, vector<int> arr) {
    // Intuition: n points must be contained in at most n + 1 spaces
    if (arr.back() - arr[0] <= n + 1) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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
