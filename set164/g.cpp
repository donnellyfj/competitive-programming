#include <bits/stdc++.h>
using namespace std;

// Palindromifier

void solve(int n) {
    // Number of operations
    cout << 3 << '\n';

    // Step 1: R 2
    cout << "R 2" << '\n';

    // Step 2: L n
    cout << "L " << n << '\n';

    // Step 3: L n-1
    cout << "L " << n - 1 << '\n';
}

int main() {
    int n;
    string arr;

    // cout << "Input array: ";
    cin >> arr;

    solve(arr.size());
}
