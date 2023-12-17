#include <bits/stdc++.h>
using namespace std;
 
// AvtoBus
 
void solve(long long int n) {
    // Intuition: Check for odd number and remainders
    if (n % 2 || n < 4) {
        cout << -1 << '\n';
        return;
    }

    long long int minVal = n / 6;
    if (n % 6) {
        minVal++;
    }
    long long int maxVal = n / 4;
    if (n % 4 && n % 4 != 2) {
        maxVal++;
    }

    cout << minVal << ' ' << maxVal << '\n';
}
 
int main() {
    int t;
    long long int n;
 
    cin >> t;
    while (t--) {
        cin >> n;
        solve(n);
    }
 
    return 0;
}
