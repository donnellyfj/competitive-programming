#include <bits/stdc++.h>
using namespace std;
 
// Make It Increasing

void solve(int n, vector<int> arr) {
    // Intuition: Go from right to left and divide numbers until less than next number.
    int out = 0;
    for (int i = n - 2; i >= 0; i--) {
        while (arr[i] >= arr[i + 1]) {
            arr[i] /= 2;
            out++;
            // If a value is 0 and it is not the first value in the array, then it is impossible
            // to create an increasing array
            if (arr[i + 1] == 0) {
                cout << -1 << '\n';
                return;
            }
        }
    }

    cout << out << '\n';
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
