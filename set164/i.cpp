#include <bits/stdc++.h>
using namespace std;

// X-Magic Pair

void solve(long long a, long long b, long long x) {
    long long n;
    while (max(a, b) >= x) {
        if (a == x || b == x || a == 1 || b == 1) {
            cout << "YES\n";
            return;
        }

        if (a == 0 || b == 0) {
            break;
        }
        
        n = 0;
        if (a >= b) {
            if (b != 0) {
                n = (a - max(b, x)) / b;
            }
            n += n == 0;
            a = a - b * n;
        }
        else {
            if (a != 0) {
                n = (b - max(a, x)) / a;
            }
            n += n == 0;
            b = b - a * n;
        }
    }
    cout << "NO\n";
}

int main() {
    int t;
    long long a, b, x;

    cin >> t;
    while (t--) {
        cin >> a >> b >> x;
        solve(a, b, x);
    }
}
