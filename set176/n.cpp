#include <bits/stdc++.h>
using namespace std;
 
// GCD Queries

void solve(int n) {
    // Intuition: For 3 indices i, j, and k, check gcd(Pi, Pj) and gcd(Pj, Pk).
    //            Use this information to eliminate potential indices.
    int i = 1;
    int j = 2;
    int gcd1;
    int gcd2;
    for (int k = 3; k <= n; k++) {
        // Check gdc(Pi, Pj) and gcd(Pj, Pk)
        cout << "? " << i << " " << j << '\n';
        cin >> gcd1;
        cout << "? " << j << " " << k << '\n';
        cin >> gcd2;

        // If gcd1 < gcd2, then we know that Pi != 0, so we can set i to k
        if (gcd1 < gcd2) {
            i = k;
        }
        // If gcd1 == gcd2, then we know that Pj != 0, so we can set j to k
        else if (gcd1 == gcd2) {
            j = k;
        }
        // If gcd1 > gcd2, then we know that Pk != 0, so we increment k via the for loop
    }

    cout << "! " << i << " " << j << '\n';
    int res;
    cin >> res;
    assert(res == 1);
}
 
int main() {
    int t;
    int n;
 
    cin >> t;
    while (t--) {
        cin >> n;
        solve(n);
    }
 
    return 0;
}
