#include <bits/stdc++.h>
using namespace std;

// Floor and Mod

void solve(long long int x, long long int y) {
    // Intuition: Let a / b = a % b = k. Iterate over possible values of k
    //            and find values of b that meet the conditions.
    long long int out = 0;
    for (long long int k = 1; k < sqrt(x); k++) {
        out += max(0ll, min(y, x / k - 1) - k);
    }

    cout << out << '\n';
}

int main() {
    int t;
    long long int x;
    long long int y;
 
    cin >> t;
    while (t--) {
        cin >> x >> y;
        solve(x, y);
    }
 
    return 0;
}
