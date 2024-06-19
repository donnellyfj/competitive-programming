#include <bits/stdc++.h>
using namespace std;

// Longest Simple Cycle

void solve(int n, vector<long long int> arr, vector<long long int> a, vector<long long int> b) {
    // Intuition: Traverse from left to right and keep track of largest cycle
    long long int out = 0;
    long long int curr = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] == b[i]) {
            curr = (arr[i] - 1) + 2;
        }
        else {
            // End cycle on current chain
            curr = max(curr - abs(b[i] - a[i]), abs(b[i] - a[i]));
            curr += 2 + (arr[i] - 1);
        }

        out = max(out, curr);
    }
    
    cout << out << '\n';
}
 
int main() {
    int t;
    int n;
    vector <long long int> arr;
    vector <long long int> a;
    vector <long long int> b;

    cin >> t;
    while (t--) {
        cin >> n;
        arr.resize(n);
        a.resize(n);
        b.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        solve(n, arr, a, b);
    }

    return 0;
}
