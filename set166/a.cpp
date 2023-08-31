#include <bits/stdc++.h>
using namespace std;

// Buttons

int main() {
    int t;
    int a;
    int b;
    int c;

    cin >> t;
    while (t--) {
        cin >> a >> b >> c;

        // Observation: If A or B is greater than the other, that player wins
        //              If A == B, an odd C means A wins, otherwise B wins
        if (a > b) {
            cout << "First\n";
        }
        else if (b > a) {
            cout << "Second\n";
        }
        else if (c % 2 == 1) {
            cout << "First\n";
        }
        else {
            cout << "Second\n";
        }
    }

    return 0;
}
