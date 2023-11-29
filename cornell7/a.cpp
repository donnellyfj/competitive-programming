#include <bits/stdc++.h>
using namespace std;
 
// Permutation
 
void solve(int n, vector<vector<int>> arr) {
    // Intuition: Find the one array with a different first element, and append it to the other first element.
    vector<int> out;
    // Check the first 3 first values to see if arr[0][0] was seen twice
    int first;
    if (arr[0][0] == arr[1][0] || arr[0][0] == arr[2][0]) {
        first = arr[0][0];
    }
    else {
        // If not arr[0] then we can pick an arbitrary index
        first = arr[1][0];
    }

    // Look for first array with different starting value
    for (int i = 0; i < n; i++) {
        if (arr[i][0] != first) {
            out = arr[i];
            break;
        }
    }

    // Print first value, then array missing first value
    cout << first << ' ';
    for (int val : out) {
        cout << val << ' ';
    }

    cout << '\n';
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
            arr[i].resize(n - 1);
            for (int j = 0; j < n - 1; j++) {
                cin >> arr[i][j];
            }
        }
        solve(n, arr);
    }
 
    return 0;
}
