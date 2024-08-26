#include <bits/stdc++.h>
using namespace std;

// Present

void solve(int n, vector<long long int> arr) {
    // Intuition: Go bit by bit for the output value
    long long int out = 0;

    // Loop through possible bits
    for (int i = 0; i < 32; i++) {
        long long int currPow = 1ll << i;
        // Mod values in arr by current power of 2
        vector<long long int> modArr;
        for (long long int val : arr) {
            modArr.push_back(val % (currPow * 2));
        }
        // Sort modded array
        sort(modArr.begin(), modArr.end());
        // Find how many pairs in modArr would result in the current bit being a 1 when added
        // This means their sum would have to be in range [2^i, 2^(i + 1)), or in range
        // [2^(i + 1) + 2^i, 2^(i + 2))
        int numPairs = 0;
        // Find first range via binary search
        int l;
        int r;
        for (int modArrIdx = 0; modArrIdx < n - 1; modArrIdx++) {
            l = lower_bound(modArr.begin() + modArrIdx + 1, modArr.end(), currPow - modArr[modArrIdx]) - modArr.begin();
            r = lower_bound(modArr.begin() + modArrIdx + 1, modArr.end(), currPow * 2 - modArr[modArrIdx]) - modArr.begin();
            // Find number of pairs whose sum is within the range
            if (l < n && modArr[modArrIdx] + modArr[l] < currPow * 2) {
                numPairs += r - l;
            }
        }
        // Find second range via binary search
        for (int modArrIdx = 0; modArrIdx < n - 1; modArrIdx++) {
            l = lower_bound(modArr.begin() + modArrIdx + 1, modArr.end(), currPow * 2 + currPow - modArr[modArrIdx]) - modArr.begin();
            r = lower_bound(modArr.begin() + modArrIdx + 1, modArr.end(), currPow * 4 - modArr[modArrIdx]) - modArr.begin();
            // Find number of pairs whose sum is within the range
            if (l < n && modArr[modArrIdx] + modArr[l] < currPow * 4ll) {
                numPairs += r - l;
            }
        }

        // If the number of pairs is odd, then the current bit will be set in the output
        if (numPairs % 2ll) {
            out += currPow;
        }
    }
    
    cout << out << '\n';
}

int main() {
    int n;
    vector<long long int> arr;

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    solve(n, arr);

    return 0;
}
