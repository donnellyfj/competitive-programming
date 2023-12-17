#include <bits/stdc++.h>
using namespace std;
 
// Constructive Problems
 
void solve(long long int n, long long int m) {
    // Intuition: Return the longest side
    cout << max(n, m) << '\n';
}
 
int main() {
    int t;
    long long int n;
    long long int m;
 
    cin >> t;
    while (t--) {
        cin >> n >> m;
        solve(n, m);
    }
 
    return 0;
}
