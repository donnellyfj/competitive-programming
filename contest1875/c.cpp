#include <bits/stdc++.h>
using namespace std;
 
// Jellyfish and Green Apple
 
void solve(int n, int m) {
    // Intuition: Distribute as many apples as possible, and cut the remainders as needed
    // Distribute apples if possible
    n %= m;

    // Check if m / gcd(n, m) is a power of 2
    if (__builtin_popcount(m / gcd(n, m)) != 1) {
        cout << -1 << '\n';
        return;
    }

    int numerator = n / gcd(n, m);
    // Cuts = people * pieces per person - original # pieces, since each cut adds one piece
    cout << (long long int) m * __builtin_popcount(numerator) - n << '\n';
}
 
int main() {
    int t;
    int n;
    int m;
 
    cin >> t;
    while (t--) {
        cin >> n >> m;
        solve(n, m);
    }
 
    return 0;
}
