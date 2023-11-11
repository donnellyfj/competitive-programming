#include <bits/stdc++.h>
using namespace std;
 
// Subsequence Permutation

void solve(int n, string s) {
    // Intuition: Sort and count number of characters out of place.
    string sSorted = s;
    sort(sSorted.begin(), sSorted.end());
    int out = 0;
    
    // Find number of differing characters
    for (int i = 0; i < n; i++) {
        out += s[i] != sSorted[i];
    }

    cout << out << '\n';
}
 
int main() {
    int t;
    int n;
    string s;
 
    cin >> t;
    while (t--) {
        cin >> n >> s;
        solve(n, s);
    }
 
    return 0;
}
