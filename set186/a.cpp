#include <bits/stdc++.h>
using namespace std;

// Balanced Array

void solve(int n) {
    // Intuition: If n is divisible by 4, print YES and split odd/even values up to n adding
    //            necessary difference to the last odd value, else print NO.
    if (n % 4) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    // Print evens
    for (int i = 2; i <= n; i += 2) {
        cout << i << ' ';
    }

    // Print odds
    for (int i = 1; i <= n; i += 2) {
        // If last odd value, add n / 2 to make up for deficit
        if (i == n - 1) {
            i += n / 2;
        }
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
