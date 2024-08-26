#include <bits/stdc++.h>
using namespace std;

// Helping the Nature

void solve(long long int n, vector<long long int> arr) {
    // Intuition: Greedy, match values from left to right, popping from the front of the array to remove duplicates
    // Use idx to simulate popping from the front of the array
    long long int idx = 0;
    long long int sub = 0;
    long long int out = 0;
    while (idx < n - 1) {
        // Remove duplicates from front of array
        while (idx < n - 1 && arr[idx] == arr[idx + 1]) {
            idx++;
        }
        if (idx == n - 1) {
            break;
        }
        // Make the first value equal to the second value
        if (arr[idx] > arr[idx + 1]) {
            // Subtract from prefix
            out += arr[idx] - arr[idx + 1];
        }
        else {
            // Subtract from suffix
            sub += arr[idx + 1] - arr[idx];
            out += arr[idx + 1] - arr[idx];
        }
        idx++;
    }
    out += abs(arr.back() - sub);
    cout << out << '\n';
}

int main() {
    long long int t;
    long long int n;
    vector<long long int> arr;

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
