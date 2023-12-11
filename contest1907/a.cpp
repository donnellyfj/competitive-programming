#include <bits/stdc++.h>
using namespace std;
 
// Rook
 
void solve(char col, int row) {
    // Intuition: Move along row and column
    for (int i = 1; i <= 8; i++) {
        if (i == row) {
            continue;
        }
        cout << col << i << '\n';
    }

    for (char c = 'a'; c <= 'h'; c++) {
        if (c == col) {
            continue;
        }
        cout << c << row << '\n';
    }
}
 
int main() {
    int t;
    char col;
    int row;
 
    cin >> t;
    while (t--) {
        cin >> col >> row;
        solve(col, row);
    }
 
    return 0;
}
