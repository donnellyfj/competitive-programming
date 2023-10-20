#include <bits/stdc++.h>
using namespace std;
 
// Cyclically Coprime
 
void solve(int n) {
    // Intuition: Print 1 through n.
    for (int i = 1; i < n + 1; i++) {
        cout << i << ' ';
    }

    cout << '\n';
}
 
int main() {
    int n;

    cin >> n;
    solve(n);
 
    return 0;
}
