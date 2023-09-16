#include <bits/stdc++.h>
using namespace std;
 
// Grid Reconstruction
 
void solve(int n) {
    // Intuition: Put odds #s on top row, evens on bottom row.
    //            Follow max min max min... pattern. evens should
    //            be the same as odds but rotated left by one.
    vector<int> odds(n);
    vector<int> evens(n);
    deque<int> oddsQ;

    for (int i = 0; i < n; i++) {
        oddsQ.push_back(i);
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            odds[i] = oddsQ.back();
            oddsQ.pop_back();
        }
        else {
            odds[i] = oddsQ.front();
            oddsQ.pop_front();
        }
    }

    // Rotate odds left
    rotate_copy(odds.begin(), odds.begin() + 1, odds.end(), evens.begin());
    for (int i : odds) {
        cout << (i + 1) * 2 - 1 << " ";
    }
    cout << '\n';
    for (int i : evens) {
        cout << (i + 1) * 2 << " ";
    }
    cout << '\n';
}
 
int main() {
    int t;
    int n;
 
    cin >> t;
    while (t--) {
        cin >> n;
        solve(n);
    }
 
    return 0;
}
