#include <bits/stdc++.h>
using namespace std;

// Array divisibility

void solve(int n) {
    // Intuition: Print values 1 to n as they will always satisfy the conditions
    for (int i = 1; i <= n; i++) {
        cout << i << ' ';
    }
    cout << '\n';
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
