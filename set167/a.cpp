#include <bits/stdc++.h>
using namespace std;
 
// Morning Sandwich
 
void solve(int b, int c, int h) {
    // Bread is limiting factor
    if (b - 1 < c + h) {
        cout << 2 * b - 1 << '\n';
    }
    else {
        cout << 2 * (c + h) + 1 << '\n';
    } 
}
 
int main() {
    int t;
    int b, c, h;
 
    cin >> t;
    while (t--) {
        cin >> b >> c >> h;
        solve(b, c, h);
    }
 
    return 0;
}
