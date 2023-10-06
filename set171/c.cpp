#include <bits/stdc++.h>
using namespace std;
 
// MEXor Mixup
 
void solve(int a, int b) {
    // Intuition: Find XOR of all values up to MEX, and then add additional values if needed.
    if (a == 0) {
        cout << 1 << '\n';
    }
    else {
        // Find XOR of all values before the MEX
        int rolling;
        if ((a - 1) % 4 == 0) {
            rolling = a - 1;
        }
        else if ((a - 1) % 4 == 1) {
            rolling = 1;
        }
        else if ((a - 1) % 4 == 2) {
            rolling = a;
        }
        else {
            rolling = 0;
        }
        // Current XOR is already equal to b
        if (rolling == b) {
            cout << a << '\n';
        }
        else {
            // If the value needed to make the XOR = b is the MEX, then we have to add
            // two numbers to the array, otherwise we just add one
            if ((rolling ^ a) == b) {
                cout << a + 2 << '\n';
            }
            else {
                cout << a + 1 << '\n';
            }
        }
    }
}
 
int main() {
    int t;
    int n;
    int a;
    int b;
 
    cin >> t;
    while (t--) {
        cin >> a >> b;
        solve(a, b);
    }
 
    return 0;
}
