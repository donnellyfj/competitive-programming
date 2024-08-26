#include <bits/stdc++.h>
using namespace std;

// Two Arrays And Swaps

void solve(int n, int k, vector<int> a, vector<int> b) {
    // Intuition: Swap at most k smallest values of a with largest values of b
    int out = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        if (a[i] < b[i] && k > 0) {
            out += b[i];
            k--;
        }
        else {
            out += a[i];
        }
    }

    cout << out << '\n';
}
 
int main() {
    int t;
    int n;
    int k;
    vector<int> a;
    vector<int> b;

    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.resize(n);
        b.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        solve(n, k, a, b);
    }

    return 0;
}
