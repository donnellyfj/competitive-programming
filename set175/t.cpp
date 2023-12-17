#include <bits/stdc++.h>
using namespace std;
 
// Conveyor
 
void solve(long long int t, long long int x, long long int y) {
    // Intuition: Simulate movement and find differing cell at time t - 1 and t
    // If diagonal is greater than the time, then it's not possible to reach
    vector<long long int> before(240, 0);
    vector<long long int> after(240, 0);
    before[0] = t - x - y;
    after[0] = t - x - y + 1;
    if (t < x + y) {
        cout << "NO\n";
        return;
    }

    // At each step, move half of the slimes to the right and half of them down
    for (long long int i = 0; i < x + y; i++) {
        for (long long int j = i; j >= 0; j--) {
            before[j + 1] += before[j] / 2;
            before[j] -= before[j] / 2;
            after[j + 1] += after[j] / 2;
            after[j] -= after[j] / 2;
        }
    }

    // Check if target cell is different before/after the time change
    if (after[x] != before[x]) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}
 
int main() {
    int q;
    long long int t;
    long long int x;
    long long int y;
 
    cin >> q;
    while (q--) {
        cin >> t >> x >> y;
        solve(t, x, y);
    }
 
    return 0;
}
