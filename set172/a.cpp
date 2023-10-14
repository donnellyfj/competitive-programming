#include <bits/stdc++.h>
using namespace std;
 
// Grasshopper on a Line
 
void solve(int x, int k) {
    // Intuition: Try to jump in one move. If divisible by k, jump by x - 1 and then 1
    if (x % k) {
        cout << 1 << '\n';
        cout << x << '\n';
    }
    else {
        cout << 2 << '\n';
        cout << x - 1 << ' ' << 1 << '\n';
    }
}
 
int main() {
    int t;
    int x;
    int k;
 
    cin >> t;
    while (t--) {
        cin >> x >> k;
        solve(x, k);
    }
 
    return 0;
}
