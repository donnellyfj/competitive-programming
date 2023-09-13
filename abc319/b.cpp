#include <bits/stdc++.h>
using namespace std;

// Measure

int main() {
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        int out = -1;
        for (int j = 1; j <= 9; j++) {
            if ((n % j) == 0 && i % (n / j) == 0) {
                out = j;
                break;
            }
        }
        if (out == -1) {
            cout << '-';
        }
        else {
            cout << out;
        }
    }
    cout << '\n';
}
