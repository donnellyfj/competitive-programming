#include <bits/stdc++.h>
using namespace std;

// Boring Day

void solve(int n, int l, int r, vector<int> arr) {
    // Intuition: Take cards until you reach l, drop cards while you are over r
    int out = 0;
    long long int currSum = 0;
    int i = 0;
    int j = 0;
    while (j < n) {
        // Take cards until window is reached
        while (currSum < l && j < n) {
            currSum += arr[j];
            j++;
        }
        // Check if within window
        if (l <= currSum && currSum <= r) {
            out++;
            currSum = 0;
            i = j;
        }
        // Drop cards if outside right bound of window
        while (currSum > r) {
            currSum -= arr[i];
            i++;
        }
    }
    // Check if within window again
    if (l <= currSum && currSum <= r) {
        out++;
        currSum = 0;
        i = j;
    }
    cout << out << '\n';
}

int main() {
    int t;
    int n;
    int l;
    int r;
    vector<int> arr;

    cin >> t;
    while (t--) {
        cin >> n >> l >> r;
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(n, l, r, arr);
    }

    return 0;
}
