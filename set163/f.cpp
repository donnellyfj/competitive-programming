#include <bits/stdc++.h>
using namespace std;

// Scoring Subsequences

void solve(int n, vector<int> arr) {
    int l = 0;
    int r;
    int m;

    for (int i = 1; i <= n; i++) {
        r = i - 1;
        while (l < r) {
            m = (l + r) / 2;
            if (arr[m] / (i - m) < 1) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }
        cout << i - l << ' ';
    }
    cout << '\n';
}

int main() {
    int i;
    int n;
    vector<int> arr;

    // cout << "Input num of test cases: ";
    scanf("%d", &i);

    while (i--) {
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
