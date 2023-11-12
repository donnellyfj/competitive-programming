#include <bits/stdc++.h>
using namespace std;
 
// Scoring Subsequences

void solve(int n, vector<int> arr) {
    // Intuition: Find the first point in each subarray where a[i] >= (b - i),
    //            where b is the end of the subarray.
    int l;
    int r;
    int m;

    // Loop through each subarray
    for (int i = 0; i < n; i++) {
        // Binary search
        l = 0;
        r = i;
        while (l < r) {
            m = (l + r) / 2;
            if (arr[m] < i - m + 1) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        cout << i - l + 1 << ' ';
    }
    cout << '\n';
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
