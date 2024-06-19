#include <bits/stdc++.h>
using namespace std;

// Shinju and the Lost Permutation

void solve(int n, vector<int> arr) {
    // Intuition: Check that the value 1 appears once and no arr[i + 1] - arr[i] > 1
    if (count(arr.begin(), arr.end(), 1) != 1) {
        cout << "NO\n";
            return;
    }

    // Make neighboring elements circular
    arr.push_back(arr.front());
    for (int i = 0; i < n; i++) {
        if (arr[i + 1] - arr[i] > 1) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
}
 
int main() {
    int t;
    int n;
    vector <int> arr;

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
