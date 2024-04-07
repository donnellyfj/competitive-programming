#include <bits/stdc++.h>
using namespace std;

// Bottom-Tier Reversals

void solve(int n, vector<int> arr) {
    // Intuition: Check if parity of values are opposite to parity of index, move each
    //            two values to the beginning before moving to their sorted position.
    // Check validity
    for (int i = 0; i < n; i++) {
        if (i % 2 == arr[i] % 2) {
            cout << "-1\n";
            return;
        }
    }

    // Print number of required operations
    cout << (n - 1) * 5 / 2 << '\n';
    // Sort permutation
    int idx;
    for (int i = n; i > 1; i -= 2) {
        // Find index of largest unsorted value
        idx = find(arr.begin(), arr.end(), i) - arr.begin();

        // Move largest unsorted value to the beginning
        reverse(arr.begin(), arr.begin() + idx + 1);
        cout << idx + 1 << ' ';

        // Find index of second largest unsorted value
        idx = find(arr.begin(), arr.end(), i - 1) - arr.begin();

        // Move largest unsorted value to right before second largest value
        reverse(arr.begin(), arr.begin() + idx);
        cout << idx << ' ';

        // Move second largest unsorted value to second element
        reverse(arr.begin(), arr.begin() + idx + 2);
        cout << idx + 2 << ' ';

        // Swap order of first three elements so they can be moved to the end
        reverse(arr.begin(), arr.begin() + 3);
        cout << 3 << ' ';

        // Move two largest unsorted values to their sorted positions
        reverse(arr.begin(), arr.begin() + i);
        cout << i << ' ';
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
