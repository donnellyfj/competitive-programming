#include <bits/stdc++.h>
using namespace std;
 
// Non-Coprime Partition

void solve(int n) {
    // Intuition: Split even and odd numbers, their sums will always be valid as long as
    //            there are at least two odd numbers.
    if (n <= 2) {
        cout << "No\n";
        return;
    }

    cout << "Yes\n";
    // Print odd numbers
    cout << n / 2 + n % 2;
    for (int i = 1; i <= n; i += 2) {
        cout << ' ' << i;
    }
    cout << '\n';
    
    // Print even numbers
    cout << n / 2;
    for (int i = 2; i <= n; i += 2) {
        cout << ' ' << i;
    }
    cout << '\n';
}

int main() {
    int n;
 
    cin >> n;
    solve(n);
 
    return 0;
}
