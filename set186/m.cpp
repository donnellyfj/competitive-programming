#include <bits/stdc++.h>
using namespace std;
 
// Keep the Average High
 
void solve(int n, int x, vector<int> arr) {
    // Intuition: Subtract x from all values, check if sum goes below 0.
    int out = n;
    for (int i = 0; i < n; i++) {
        arr[i] -= x;
    }

    for (int i = 1; i < n; i++) {
        // Length of negative sum can only be at most 3 because you can skip an element
        if (arr[i] + arr[i - 1] < 0) {
            arr[i] = 400000;
            out--;
        }
        if (i > 1 and arr[i] + arr[i - 1] + arr[i - 2] < 0) {
            arr[i] = 400000;
            out--;
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
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> x;
        solve(n, x, arr);
    }
 
    return 0;
}
