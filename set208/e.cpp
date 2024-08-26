#include <bits/stdc++.h>
using namespace std;

// Chamo and Mocha's Array

void solve(int n, vector<int> arr) {
    // Intuition: Output the largest number that appears next to a larger/equal number,
    //            as well as second largest in each sliding window group of 3
    int out = *min_element(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] <= arr[i - 1]) {
            out = max(out, arr[i]);
        }
        if (i < n - 1 && arr[i] <= arr[i + 1]) {
            out = max(out, arr[i]);
        }
    }

    // Try groups of 3
    for (int i = 0; i < n - 2; i++) {
        vector<int> temp = {arr[i], arr[i + 1], arr[i + 2]};
        sort(temp.begin(), temp.end());
        out = max(out, temp[1]);
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
