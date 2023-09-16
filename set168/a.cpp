#include <bits/stdc++.h>
using namespace std;
 
// Buttons
 
void solve(int a, int b, int c) {
    // Intuition: Use button c first. If c is even, then p2 as an advantage, else p1.
    //            If a = b, player with advantage wins. Otherwise, player with more
    //            buttons wins.
    if (a == b) {
        if (c % 2) {
            cout << "First\n";
        }
        else {
            cout << "Second\n";
        }
    }
    else if (a > b) {
        cout << "First\n";
    }
    else {
        cout << "Second\n";
    }
}
 
int main() {
    int t;
    int a, b, c;
 
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        solve(a, b, c);
    }
 
    return 0;
}
