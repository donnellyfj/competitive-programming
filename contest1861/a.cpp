#include <bits/stdc++.h>
using namespace std;

// Prime Deletion

int main() {
    int t;
    long long int x;

    cin >> t;
    while (t--) {
        cin >> x;
        
        // Intuition: Return either 13 or 31, whichever is present in the sequence.
        while (x > 0) {
            if (x % 10 == 3) {
                cout << 13 << '\n';
                break;
            }
            else if (x % 10 == 1) {
                cout << 31 << '\n';
                break;
            }
            x /= 10;
        }
    }

    return 0;
}
