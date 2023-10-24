#include <bits/stdc++.h>
using namespace std;
 
// Balanced Substring
 
void solve(int n, string s) {
    // Intuition: Find the first ab or ba substring
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) {
            cout << i + 1 << ' ' << i + 2 << '\n';
            return;
        }
    }

    cout << -1 << ' ' << -1 << '\n';
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
