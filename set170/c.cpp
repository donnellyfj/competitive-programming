#include <bits/stdc++.h>
using namespace std;
 
// Coloring Rectanges
 
void solve(int n, int m) {
    // Intuition: Cut into as many 1x3 sized pieces as possible, and then cut the remanders
    //            into 1x2 sized pieces. Each piece should have one square painted blue, so
    //            find the number of different pieces.
    int area = n * m;
    int threes = area / 3;

    // Rectangle evenly divides into 1x3s
    if (area % 3 == 0) {
        cout << threes << '\n';
    }
    // Subtract a 1x3 and add two 1x2s
    else if (area % 3 == 1) {
        cout << threes - 1 + 2 << '\n';
    }
    // Add a 1x2
    else {
        cout << threes + 1 << '\n';
    }
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
