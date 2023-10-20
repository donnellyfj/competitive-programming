#include <bits/stdc++.h>
using namespace std;
 
// Hemose Shopping
 
void solve(int n, int x, vector<int> arr) {
    // Intuition: Sort array, compare range of impossible swaps.
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    for (int i = n - x; i < x; i++) {
        if (arr[i] != sortedArr[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}
 
int main() {
    int t;
    int n;
    int x;
    vector<int> arr;
 
    cin >> t;
    while (t--) {
        cin >> n >> x;;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(n, x, arr);
    }
 
    return 0;
}
