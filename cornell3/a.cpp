#include <bits/stdc++.h>
using namespace std;
 
// Deadly Laser

void solve(int n, int m, int Sx, int Sy, int d) {
    // Intuition: If it is possible to get to the end, distance will always be n + m - 2.
    // Check if laser touches top and left walls
    if (Sx - d <= 1 && Sy - d <= 1) {
        cout << -1 << '\n';
    }
    // Check if laser touches bottom and right walls
    else if (Sx + d >= n && Sy + d >= m) {
        cout << -1 << '\n';
    }
    // Check if laser touches left and right walls
    else if (Sy - d <= 1 && Sy + d >= m) {
        cout << -1 << '\n';
    }
    // Check if laser touches top and bottom walls
    else if (Sx - d <= 1 && Sx + d >= n) {
        cout << -1 << '\n';
    }
    // It is possible to reach (n, m)
    else {
        cout << n + m - 2 << '\n';
    }
}
 
int main() {
    int t;
    int n;
    int m;
    int Sx;
    int Sy;
    int d;
 
    cin >> t;
    while (t--) {
        cin >> n >> m >> Sx >> Sy >> d;
        solve(n, m, Sx, Sy, d);
    }
 
    return 0;
}
