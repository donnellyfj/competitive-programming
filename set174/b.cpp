#include <bits/stdc++.h>
using namespace std;
 
// Burenka Plays with Fractions

void solve(long long int a, long long int b, long long int c, long long int d) {
    // Intuition: Then check if you can multiply by a number to make fractions equal.
    // Simplify fractions
    long long int gcdAB = gcd(a, b);
    long long int gcdCD = gcd(c, d);
    a /= gcdAB;
    b /= gcdAB;
    c /= gcdCD;
    d /= gcdCD;
    // Check if fractions are equal
    if (a == c && b == d) {
        cout << 0 << '\n';
    }
    // Check if numbeator is 0
    else if (a == 0 || c == 0) {
        cout << 1 << '\n';
    }
    else {
        // Cross multiply
        long long mult1 = a * d;
        long long mult2 = b * c;
        if (mult1 % mult2 == 0 || mult2 % mult1 == 0) {
            cout << 1 << '\n';
        }
        else {
            cout << 2 << '\n';
        }
    }
}
 
int main() {
    int t;
    long long int a;
    long long int b;
    long long int c;
    long long int d;
 
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        solve(a, b, c, d);
    }
 
    return 0;
}
