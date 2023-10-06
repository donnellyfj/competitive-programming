#include <bits/stdc++.h>
using namespace std;
 
// Kill the Monster

void solve(long long int hc, long long int dc, long long int hm, long long int dm, long long int k, long long int w, long long int a) {
    // Intuition: Loop through all possible coin combinations and find outcome.
    // Start with all coins on health and move them over to damage
    hc += a * k;

    while (k >= 0) {
        // Simulate outcome - find how many turns it would take to kill each character
        //                    Max of 1 and ceil(hx / dy)
        // Number of turns for c to kill m
        long long int cTurns = max(1ll, (hm + dc - 1) / dc);
        // Number of turns for m to kill c
        long long int mTurns = max(1ll, (hc + dm - 1) / dm);
        if (cTurns <= mTurns) {
            cout << "YES\n";
            return;
        }

        // Move one coin from health to damage
        hc -= a;
        dc += w;
        k--;
    }
    cout << "NO\n";
}
 
int main() {
    int t;
    long long int hc, dc;
    long long int hm, dm;
    long long int k, w, a;
 
    cin >> t;
    while (t--) {
        cin >> hc >> dc;
        cin >> hm >> dm;
        cin >> k >> w >> a;
        solve(hc, dc, hm, dm, k, w, a);
    }
 
    return 0;
}
