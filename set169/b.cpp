#include <bits/stdc++.h>
using namespace std;
 
// Lucky Numbers
 
void solve(int l, int r) {
    // Intuition: The max possible luckiness is 9, which is guaranteed to happen within
    //            the first 100 numbers. So just keep track of the max until you see a 9,
    //            and then return either a 9 or the max luckiness seen.

    int luck = 0;
    int out = l;
    set<int> digits;

    while (l <= r) {
        // Clear the queue
        digits.clear();
        int temp = l;

        while (temp) {
            digits.insert(temp % 10);
            temp /= 10;
        }

        if (*digits.rbegin() - *digits.begin() > luck) {
            luck = *digits.rbegin() - *digits.begin();
            out = l;
        }

        if (luck == 9) {
            break;
        }

        l++;
    }

    cout << out << '\n';
}
 
int main() {
    int t;
    int l, r;
 
    cin >> t;
    while (t--) {
        cin >> l >> r;
        solve(l, r);
    }
 
    return 0;
}
