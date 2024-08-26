#include <bits/stdc++.h>
using namespace std;

// Shovels and Swords

void solve(int a, int b) {
    // Intuition: Try to make a and b equal, then alternate as long as you can
    int out = 0;
    // Keep a <= b for conistency
    if (a > b) {
        swap(a, b);
    }
    out = min(a, b - a);
    a -= out;
    b -= out * 2;

    // Alternating sword/shovel uses 3 of each resource, and we know a <= b
    int numBoth = a / 3;
    a -= numBoth * 3;
    b -= numBoth * 3;
    out += numBoth * 2;

    // If a = 2 and b = 2, make one more of either item
    if (a == 2 && b == 2) {
        out++;
    }
    
    cout << out << '\n';
}
 
int main() {
    int t;
    int a;
    int b;

    cin >> t;
    while (t--) {
        cin >> a >> b;
        solve(a, b);
    }

    return 0;
}
