#include <bits/stdc++.h>
using namespace std;
 
// Vasilije in Cacak
 
void solve(long long int n, long long int k, long long int x) {
    // Intuition: If x is within the max and min possible sums, print YES, otherwise print NO.
    // Use Gaussian sums
    long long int minSum = k * (k + 1) / 2;
    long long int maxSum = (n * (n + 1) - (n - k) * (n - k + 1)) / 2;
    
    if (x >= minSum and x <= maxSum) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}
 
int main() {
    int t;
    long long int n;
    long long int k;
    long long int x;
 
    cin >> t;
    while (t--) {
        cin >> n >> k >> x;
        solve(n, k, x);
    }
 
    return 0;
}
