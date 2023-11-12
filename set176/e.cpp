#include <bits/stdc++.h>
using namespace std;
 
// Penalty

void solve(string s) {
    // Intuition: Take mininum of having one team make all shots and one team miss all shots.
    int evenGoals = 0;
    int oddGoals = 0;
    int evenLeft = 5;
    int oddLeft = 5;
    int out1 = 0;

    // Have even team make all shots and odd team miss all shots
    for (int i = 0; i < 10; i++) {
        if (i % 2) {
            if (s[i] == '1') {
                oddGoals++;
            }
            oddLeft--;
        }
        else {
            if (s[i] == '1' || s[i] == '?') {
                evenGoals++;
            }
            evenLeft--;
        }
        out1++;

        // If losing team can't catch winning team, break
        if (evenGoals < oddGoals && oddGoals - evenGoals > evenLeft) {
            break;
        }
        else if (oddGoals < evenGoals && evenGoals - oddGoals > oddLeft) {
            break;
        }
    }

    // Have odd team make all shots and even team miss all shots
    evenGoals = 0;
    oddGoals = 0;
    evenLeft = 5;
    oddLeft = 5;
    int out2 = 0;
    for (int i = 0; i < 10; i++) {
        if (i % 2) {
            if (s[i] == '1' || s[i] == '?') {
                oddGoals++;
            }
            oddLeft--;
        }
        else {
            if (s[i] == '1') {
                evenGoals++;
            }
            evenLeft--;
        }
        out2++;

        // If losing team can't catch winning team, break
        if (evenGoals < oddGoals && oddGoals - evenGoals > evenLeft) {
            break;
        }
        else if (oddGoals < evenGoals && evenGoals - oddGoals > oddLeft) {
            break;
        }
    }

    cout << min(out1, out2) << '\n';
}
 
int main() {
    int t;
    int n;
    string s;
 
    cin >> t;
    while (t--) {
        cin >> s;
        solve(s);
    }
 
    return 0;
}
