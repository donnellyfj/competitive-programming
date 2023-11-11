#include <bits/stdc++.h>
using namespace std;
 
// Coloring Rectangles

void solve(int n, int m) {
    // Intuition: Split into as many 1x3 sized pieces as possible, and then split the remainders into 1x2 sized pieces.
    //            Each piece should have 1 square painted, so just count the number of pieces.
    int area = n * m;
    int out = area / 3;

    if (area % 3) {
        // If area % 3 = 1, remove a 1x3 and add two 1x2
        // If area % 3 = 2, we have a 1x2 piece left over
        // Both scenarios result in a net gain of 1 piece
        out++;
    }

    cout << out << '\n';
}
 
int main() {
    int t;
    int n;
    int m;
 
    cin >> t;
    while (t--) {
        cin >> n >> m;
        solve(n, m);
    }
 
    return 0;
}
