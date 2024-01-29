#include <bits/stdc++.h>
using namespace std;
 
// Circle Game

void solve(int d, int k) {
    // Intuition: Find the largest integer x such that (k*x, k*x) is in the circle. If (k*x, k*(x + 1)) is in the circle,
    //            then p1 can always win, otherwise p2 can always win.
    int curr = 0;
    while (pow(k * curr, 2) * 2 <= pow(d, 2)) {
        curr++;
    }
    curr--;

    if (pow(k * curr, 2) + pow(k * (curr + 1), 2) <= pow(d, 2)) {
        cout << "Ashish\n";
    }
    else {
        cout << "Utkarsh\n";
    }
}

int main() {
    int t;
    int d;
    int k;
 
    cin >> t;
    while (t--) {
        cin >> d >> k;
        solve(d, k);
    }
 
    return 0;
}
