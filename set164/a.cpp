#include <bits/stdc++.h>
using namespace std;

// Working Week

void solve(int n) {
    cout << n / 3 - 2 << '\n';
}

int main() {
    int t;
    int n;

    // cout << "Input num of test cases: ";
    scanf("%d", &t);

    while (t--) {
        // cout << "Input array size: ";
        scanf("%d", &n);

        solve(n);
    }
}