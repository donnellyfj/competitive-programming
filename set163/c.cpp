#include <bits/stdc++.h>
using namespace std;

// Bestie

void solve(int n, vector<int> arr) {
    // Check if gdc of arr is 1
    int rollingGCD = arr[0];
    for (int val : arr) {
        rollingGCD = gcd(rollingGCD, val);
        if (rollingGCD == 1) {
            cout << 0 << '\n';
            return;
        }
    }

    if (gcd(rollingGCD, n) == 1) {
        cout << 1 << '\n';
        return;
    }
    else if (gcd(rollingGCD, n - 1) == 1) {
        cout << 2 << '\n';
        return;
    }
    else {
        cout << 3 << '\n';
        return;
    }
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