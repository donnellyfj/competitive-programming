#include <bits/stdc++.h>
using namespace std;
 
// Gregor and the Pawn Game

void solve(int n, string e, string g) {
    // Intuition: Greedily check to see if each pawn can make it to the end.
    vector<int> taken(n, 0);
    int out = 0;

    for (int i = 0; i < n; i++) {
        if (g[i] == '1') {
            // Gregor has a pawn at i
            if (e[i] == '0' and taken[i] == 0) {
                // There is no enemy pawn straight ahead and the space is free
                // We can just move the pawn straight forward
                taken[i] = 1;
                out++;
            }
            // Try to take pawn on the left
            else if (i > 0 && e[i - 1] == '1' && taken[i - 1] == 0) {
                taken[i - 1] = 1;
                out++;
            }
            // Try to take pawn on the right
            else if (i < n - 1 && e[i + 1] == '1' && taken[i + 1] == 0) {
                taken[i + 1] = 1;
                out++;
            }
        }
    }

    cout << out << '\n';
}
 
int main() {
    int t;
    int n;
    string e;
    string g;
 
    cin >> t;
    while (t--) {
        cin >> n >> e >> g;
        solve(n, e, g);
    }
 
    return 0;
}
