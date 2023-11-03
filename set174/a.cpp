#include <bits/stdc++.h>
using namespace std;
 
// The Third Three Number Problem

void solve(int n) {
    // Intuition: There is a solution if the number is even, so you can use two zeros and n / 2.
    if (n % 2) {
        cout << -1 << '\n';
    }
    else {
        cout << 0 << " " << 0 << " " << n / 2 << '\n';
    }
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
