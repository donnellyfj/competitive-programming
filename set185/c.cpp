#include <bits/stdc++.h>
using namespace std;

// Board Moves

void solve(long long int n) {
    // Intuition: Add distances from each odd number up to n.
    long long int out = 0;
    while (n > 1) {
        out += 8 * (n / 2) * (n / 2);
        n -= 2;
    }
    cout << out << '\n';
}

int main() {
    int t;
    long long int n;
 
    cin >> t;
    while (t--) {
        cin >> n;
        solve(n);
    }
 
    return 0;
}
