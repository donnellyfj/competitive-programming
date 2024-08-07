#include <bits/stdc++.h>
using namespace std;

// New Bakery

void solve(long long int n, long long int a, long long int b) {
    // Intuition: Binary search, sell at modified price as long as it is higher than a
    long long int out = 0;
    long long int r = min(n, b);
    long long int l = 0;
    long long int m;
    while (l < r) {
        m = (l + r + 1) / 2;
        if (b - (m + 1) + 1 >= a) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }
    
    // Gaussian sum for all of the i values
    out = l * (b + 1) - (l * (l + 1) / 2);
    out += (n - l) * a;
    cout << out << '\n';
}

int main() {
    int t;
    long long int n;
    long long int a;
    long long int b;

    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        solve(n, a, b);
    }

    return 0;
}
