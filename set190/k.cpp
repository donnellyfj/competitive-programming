#include <bits/stdc++.h>
using namespace std;

// Guess the Cycle Size

void solve() {
    // Intuition: Guess for (1, i) and (i, 1) with i going from 2 to 26.
    long long int val1;
    long long int val2;
    for (int i = 2; i <= 26; i++) {
        cout << "? 1 " << i << '\n';
        cin >> val1;
        cout << "? " << i << " 1\n";
        cin >> val2;

        if (val1 == -1) {
            cout << "! " << i - 1 << '\n';
            return;
        }
        if (val1 != val2) {
            cout << "! " << val1 + val2 << '\n';
            return;
        }
    }
}

int main() {
    solve();
 
    return 0;
}
