#include <bits/stdc++.h>
using namespace std;

// Sorting By Multiplication

void solve (int n, vector<int> arr) {
    int numUnsort = 0; // Number of number pairs out of order in original array
    for (int i = 0; i < n -1; i++) {
        if (arr[i] >= arr[i + 1]) {
            numUnsort++;
        }
    }

    // Test all possible negative prefixes
    int out = n;
    int negUnsort = 0;
    int negOp = 0; // Whether or not a *-1 operation was made
    for (int negIdx = 0; negIdx < n; negIdx++) {
        if (negIdx > 0) {
            negOp = 1;
        }
        // Minimum of current out vs # of positive out of order nums + # of negative out of order nums + 1 operation to make nums negative
        out = min(out, numUnsort + negUnsort + negOp); 

        if (negIdx > 0) {
            // Nums were originally in order (or equal), but aren't anymore now that they're negative
            if (arr[negIdx - 1] <= arr[negIdx]) {
                negUnsort++;
            }
        }

        if (negIdx < n - 1) {
            // Nums were originally out of order (or equal), but now they are in order since they're negative
            if (arr[negIdx] >= arr[negIdx + 1]) {
                numUnsort--;
            }
        }
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

        // Intuition: Repeatedly subtract largest power of 2 that is less than the current value,
        //            and that evenly divides current value.
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        solve(n, arr);
    }

    return 0;
}
