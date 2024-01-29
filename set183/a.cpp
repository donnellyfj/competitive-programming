#include <bits/stdc++.h>
using namespace std;
 
// Robot Cleaner

void solve(int n, int m, int r, int c, int rd, int cd) {
    // Intuition: Simulate the movement.
    int dr = 1;
    int dc = 1;
    int out = 0;
    while (r != rd && c != cd) {
        // Reverse direction of movement if you hit a boundary
        if ((r == n && dr == 1) || (r == 1 && dr == -1)) {
            dr *= -1;
        }
        if ((c == m && dc == 1) || (c == 1 && dc == -1)) {
            dc *= -1;
        }
        r += dr;
        c += dc;
        out++;
    }
    
    cout << out << '\n';
}

int main() {
    int t;
    int n;
    int m;
    int r;
    int c;
    int rd;
    int cd;
 
    cin >> t;
    while (t--) {
        cin >> n >> m >> r >> c >> rd >> cd;
        solve(n, m, r, c, rd, cd);
    }
 
    return 0;
}
