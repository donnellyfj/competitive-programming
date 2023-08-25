#include <bits/stdc++.h>
using namespace std;

// Polycarp Recovers the Permutation

void solve(int n, vector<int> arr) {
    int parity;
    int color;
    int maxIdx = distance(arr.begin(), max_element(arr.begin(), arr.end()));

    if (maxIdx != 0 and maxIdx != n - 1) {
        cout << -1 << '\n';
        return;
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    int n;
    vector<int> arr;

    // cout << "Input num of test cases: ";
    scanf("%d", &t);

    while (t--) {
        // cout << "Input array size: ";
        scanf("%d", &n);
        arr.resize(n);
        // cout << "Input array: ";
        for (int idx = 0; idx < n; idx++) {
            scanf("%d", &arr[idx]);
        }

        solve(n, arr);
    }
}
